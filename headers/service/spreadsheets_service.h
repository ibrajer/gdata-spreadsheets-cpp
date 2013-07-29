#ifndef GDATA_SPREADSHEETS_CPP_SPREADSHEETS_SERVICE_H_
#define GDATA_SPREADSHEETS_CPP_SPREADSHEETS_SERVICE_H_

class SpreadsheetsService
{
public:
	SpreadsheetsService();
	~SpreadsheetsService();

	void set_authorization_token(const std::string& token);
};

#endif /* GDATA_SPREADSHEETS_CPP_SPREADSHEETS_SERVICE_H_ */
