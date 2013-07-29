#include "../../headers/auth/client_login.h"

#include <iostream>

#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/MediaType.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/URI.h>
#include <Poco/StreamCopier.h>

#include "../../headers/utils/exceptions.h"

using namespace Poco::Net;
using namespace Poco;

namespace gdata {
namespace auth {

const std::string ClientLogin::kAuthorizationTag = "Auth=";

ClientLogin::ClientLogin(const std::string& email, const std::string& password)
	: m_email(email), m_password(password)
{
}

ClientLogin::~ClientLogin()
{
}

std::string ClientLogin::get_authorization_token()
{
	try
	{
		URI uri("https://www.google.com/accounts/ClientLogin");
		uri.setRawQuery(make_query());

		Context::Ptr context(new Context(Context::CLIENT_USE, "", Context::VERIFY_NONE));
		HTTPSClientSession session(uri.getHost(), uri.getPort(), context);

		std::string path(uri.getPathAndQuery());
		HTTPRequest request(HTTPRequest::HTTP_POST, path, HTTPMessage::HTTP_1_0);

		MediaType content_type("application/x-www-form-urlencoded");
		request.setContentType(content_type);
		request.setContentLength(0);

		session.sendRequest(request);

		HTTPResponse response;
		std::istream &is = session.receiveResponse(response);

		if (response.getStatus() != HTTPResponse::HTTP_OK)
			throw utils::ClientLoginException("Response status is not OK");

		std::string output;
		StreamCopier::copyToString(is, output);

		output = extract_token(output);
		return output;
	}
	catch (Exception &ex)
	{
		throw utils::ClientLoginException("Message is not received");
	}
}

std::string ClientLogin::extract_token(const std::string& value)
{
	std::size_t position = value.find(kAuthorizationTag);

	if (position == std::string::npos)
		throw utils::ClientLoginException("Authorization data not found in received message");

	return value.substr(position + kAuthorizationTag.length());
}

std::string ClientLogin::make_query()
{
	std::string query = "accountType=HOSTED_OR_GOOGLE&";

	query += "Email=" + m_email + "&";
	query += "Passwd=" + m_password + "&";
	query += "service=wise&";
	query += "source=ClientApp-GDataSpreadsheetsCpp-1.0";

	return query;
}

} // namespace auth
} // namespace gdata
