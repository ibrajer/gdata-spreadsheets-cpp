#include "../../headers/service/https_query.h"

#include <iostream>

#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/MediaType.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/URI.h>
#include <Poco/StreamCopier.h>
#include <Poco/NumberFormatter.h>

#include "../../headers/utils/exceptions.h"

namespace gdata {
namespace service {

HTTPSQuery::MessageNotReceivedException::MessageNotReceivedException()
	: utils::GDataException("Response message is not received")
{
}

HTTPSQuery::MessageNotReceivedException::~MessageNotReceivedException() throw()
{
}

HTTPSQuery::ResponseCodeException::ResponseCodeException(uint32_t response_code)
	: utils::GDataException("Response code is " + Poco::NumberFormatter().format(response_code))
{
}

HTTPSQuery::ResponseCodeException::~ResponseCodeException() throw()
{
}

HTTPSQuery::HTTPSQuery()
	: m_uri(""), m_method(""), m_data(""),
	  m_headers(std::map<std::string, std::string>()), m_query("")
{
}

HTTPSQuery::~HTTPSQuery()
{
}

void HTTPSQuery::add_header(const std::string& name, const std::string& value)
{
	m_headers[name] = value;
}

void HTTPSQuery::add_query_field(const std::string& name, const std::string& value)
{
	if (m_query.length())
		m_query += "&";

	m_query += name + "=" + value;
}

std::string HTTPSQuery::run()
{
	try
	{
		Poco::URI uri(m_uri);
		uri.setRawQuery(m_query);

		Poco::Net::Context::Ptr context(new Poco::Net::Context(Poco::Net::Context::CLIENT_USE,
															   "", Poco::Net::Context::VERIFY_NONE));
		Poco::Net::HTTPSClientSession session(uri.getHost(), uri.getPort(), context);

		std::string path(uri.getPathAndQuery());
		Poco::Net::HTTPRequest request(m_method, path, Poco::Net::HTTPMessage::HTTP_1_0);

		for (std::map<std::string, std::string>::iterator iter = m_headers.begin();
			 iter != m_headers.end(); ++iter)
			request.set(iter->first, iter->second);

		session.sendRequest(request);

		Poco::Net::HTTPResponse response;
		std::istream &is = session.receiveResponse(response);

		if (response.getStatus() != Poco::Net::HTTPResponse::HTTP_OK)
			throw ResponseCodeException(response.getStatus());

		std::string output;
		Poco::StreamCopier::copyToString(is, output);

		return output;
	}
	catch (Poco::Exception &ex)
	{
		throw MessageNotReceivedException();
	}
}

void HTTPSQuery::set_data(const std::string& data)
{
	m_data = data;
}

void HTTPSQuery::set_method(const HTTPMethod& method)
{
	m_method = method_to_string(method);
}

void HTTPSQuery::set_uri(const std::string& uri)
{
	m_uri = uri;
}

} // namespace service
} // namespace gdata
