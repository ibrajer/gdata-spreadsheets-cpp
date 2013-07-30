#ifndef GDATA_SPREADSHEETS_CPP_HTTP_METHODS_H_
#define GDATA_SPREADSHEETS_CPP_HTTP_METHODS_H_

namespace gdata {
namespace service {

enum class HTTPMethod
{
	DELETE,
	GET,
	POST,
	PUT
};

namespace {

std::string method_to_string(const HTTPMethod& method)
{
	switch (method)
	{
		case HTTPMethod::DELETE:
			return "DELETE";
		case HTTPMethod::GET:
			return "GET";
		case HTTPMethod::POST:
			return "POST";
		default:
			return "PUT";
	}
}

}

} // namespace service
} // namespace gdata


#endif /* GDATA_SPREADSHEETS_CPP_HTTP_METHODS_H_ */
