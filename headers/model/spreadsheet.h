#ifndef GDATA_SPREADSHEETS_CPP_SPREADSHEET_H_
#define GDATA_SPREADSHEETS_CPP_SPREADSHEET_H_

namespace gdata {
namespace model {

class Spreadsheet
{
public:
	Spreadsheet(const std::string& key);
	~Spreadsheet();

private:
	const std::string m_key;
};

} // namespace data
} // namespace gdata


#endif /* GDATA_SPREADSHEETS_CPP_SPREADSHEET_H_ */
