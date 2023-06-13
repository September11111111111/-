
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
class handle
{
public:
	void borrow(const std::string& bookName);
	void returnchange(const std::string & bookName);
	void changepassword(const std::string& userName, const std::string& newPassword);
	void deletestu(const std::string& studentId);
	void deletebook(const std::string& bookName);
	void changemanageinformation(const std::string& managename, const std::string& newmanagename, const std::string& newpassword);
	void revisebookinformation(const std::string& rootbookName, const std::string& changedbookName, const std::string bookAuthor, const std::string bookISBN, const std::string type, const std::string bookPressconst, bool bookStatue);
};