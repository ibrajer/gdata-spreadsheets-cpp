#include "../../headers/service/spreadsheets_service.h"

namespace gdata {
namespace service {

SpreadsheetsService::SpreadsheetsService()
{
}

SpreadsheetsService::~SpreadsheetsService()
{
}

std::string SpreadsheetsService::get_spreadsheets_feed()
{
	return "";
}

void SpreadsheetsService::set_authorization_token(const std::string& token)
{
	m_token = token;
}

} // namespace service
} // namespce gdata
