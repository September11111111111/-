#include"handle.h"
void handle::borrow(const std::string& bookName) 
{
    std::ifstream inFile("store.txt");
    if (!inFile) {
        std::cerr << "无法打开输入文件\n";
        return;
    }

    std::vector<std::vector<std::string>> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream sin(line);
        std::vector<std::string> fields;
        std::string field;
        while (sin >> field) {
            fields.push_back(field);
        }
        lines.push_back(fields);
    }
    inFile.close();

    // 在这里修改lines的内容
    for (auto& fields : lines) {
        if (!fields.empty() && fields[0] == bookName && fields.size() > 5 && fields[5] == "0") {
            fields[5] = "1";  // 将状态从0更改为1
        }
    }

    std::ofstream outFile("store.txt");
    if (!outFile) {
        std::cerr << "无法打开输出文件\n";
        return;
    }

    // 把修改后的内容写回文件
    for (const auto& fields : lines) {
        for (size_t i = 0; i < fields.size(); ++i) {
            if (i > 0) {
                outFile << ' ';
            }
            outFile << fields[i];
        }
        outFile << '\n';
    }
}
void handle::returnchange(const std::string& bookName)
{
    std::ifstream inFile("store.txt");
    if (!inFile) {
        std::cerr << "无法打开输入文件\n";
        return;
    }

    std::vector<std::vector<std::string>> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream sin(line);
        std::vector<std::string> fields;
        std::string field;
        while (sin >> field) {
            fields.push_back(field);
        }
        lines.push_back(fields);
    }
    inFile.close();

    // 在这里修改lines的内容
    for (auto& fields : lines) {
        if (!fields.empty() && fields[0] == bookName && fields.size() > 5 && fields[5] == "1") {
            fields[5] = "0";  // 将状态从0更改为1
        }
    }

    std::ofstream outFile("store.txt");
    if (!outFile) {
        std::cerr << "无法打开输出文件\n";
        return;
    }

    // 把修改后的内容写回文件
    for (const auto& fields : lines) {
        for (size_t i = 0; i < fields.size(); ++i) {
            if (i > 0) {
                outFile << ' ';
            }
            outFile << fields[i];
        }
        outFile << '\n';
    }
}
void handle::changepassword(const std::string& userName, const std::string& newPassword)
{
    std::ifstream inFile("student.txt");
    if (!inFile) {
        std::cerr << "无法打开输入文件\n";
        return;
    }
    std::vector<std::vector<std::string>> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream sin(line);
        std::vector<std::string> fields;
        std::string field;
        while (sin >> field) {
            fields.push_back(field);
        }
        lines.push_back(fields);
    }
    inFile.close();

    // 在这里修改lines的内容
    for (auto& fields : lines) {
        if (!fields.empty() && fields[0] == userName && fields.size() > 2) { // 找到用户名且确保有密码字段
            fields[2] = newPassword;  // 更改密码
        }
    }

    std::ofstream outFile("student.txt");
    if (!outFile) {
        std::cerr << "无法打开输出文件\n";
        return;
    }

    // 把修改后的内容写回文件
    for (const auto& fields : lines) {
        for (size_t i = 0; i < fields.size(); ++i) {
            if (i > 0) {
                outFile << ' ';
            }
            outFile << fields[i];
        }
        outFile << '\n';
    }
}
void handle::deletestu(const std::string& studentId)
{
    std::ifstream inFile("student.txt");
    if (!inFile) {
        std::cerr << "无法打开输入文件\n";
        return;
    }

    std::vector<std::vector<std::string>> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream sin(line);
        std::vector<std::string> fields;
        std::string field;
        while (sin >> field) {
            fields.push_back(field);
        }
        lines.push_back(fields);
    }
    inFile.close();

    // 在这里修改lines的内容
    lines.erase(std::remove_if(lines.begin(), lines.end(),
        [&studentId](const std::vector<std::string>& fields) {
            return !fields.empty() && fields[0] == studentId;  // 删除学号匹配的行
        }), lines.end());

    std::ofstream outFile("student.txt");
    if (!outFile) {
        std::cerr << "无法打开输出文件\n";
        return;
    }

    // 把修改后的内容写回文件
    for (const auto& fields : lines) {
        for (size_t i = 0; i < fields.size(); ++i) {
            if (i > 0) {
                outFile << ' ';
            }
            outFile << fields[i];
        }
        outFile << '\n';
    }
}
void handle::deletebook(const std::string& bookName)
{
    std::ifstream inFile("store.txt");
    if (!inFile) {
        std::cerr << "无法打开输入文件\n";
        return;
    }

    std::vector<std::vector<std::string>> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream sin(line);
        std::vector<std::string> fields;
        std::string field;
        while (sin >> field) {
            fields.push_back(field);
        }
        lines.push_back(fields);
    }
    inFile.close();

    // 在这里修改lines的内容
    lines.erase(std::remove_if(lines.begin(), lines.end(),
        [&bookName](const std::vector<std::string>& fields) {
            return !fields.empty() && fields[0] == bookName;  // 删除学号匹配的行
        }), lines.end());

    std::ofstream outFile("store.txt");
    if (!outFile) {
        std::cerr << "无法打开输出文件\n";
        return;
    }

    // 把修改后的内容写回文件
    for (const auto& fields : lines) {
        for (size_t i = 0; i < fields.size(); ++i) {
            if (i > 0) {
                outFile << ' ';
            }
            outFile << fields[i];
        }
        outFile << '\n';
    }
}
void handle::revisebookinformation(const std::string& rootbookName, const std::string& changedbookName, const std::string bookAuthor, const std::string bookISBN, const std::string type, const std::string bookPress, const bool bookStatue)
{
    std::ifstream inFile("store.txt");
    if (!inFile) {
        std::cerr << "无法打开输入文件\n";
        return;
    }

    std::vector<std::vector<std::string>> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream sin(line);
        std::vector<std::string> fields;
        std::string field;
        while (sin >> field) {
            fields.push_back(field);
        }
        lines.push_back(fields);
    }
    inFile.close();

    // 在这里修改lines的内容
    for (auto& fields : lines) {
        if (!fields.empty()&& fields[0]== rootbookName) { // 找到用户名且确保有密码字段
            fields[0] = changedbookName;  
            fields[1] = bookAuthor;
            fields[2] = bookISBN;
            fields[3] = type;
            fields[4] = bookPress;
            fields[5] = bookStatue;
        }
    }

    std::ofstream outFile("store.txt");
    if (!outFile) {
        std::cerr << "无法打开输出文件\n";
        return;
    }

    // 把修改后的内容写回文件
    for (const auto& fields : lines) {
        for (size_t i = 0; i < fields.size(); ++i) {
            if (i > 0) {
                outFile << ' ';
            }
            outFile << fields[i];
        }
        outFile << '\n';
    }
}
void handle::changemanageinformation(const std::string& managename, const std::string& newmanagename, const std::string& newpassword)
{
    std::ifstream inFile("manage.txt");
    if (!inFile) {
        std::cerr << "无法打开输入文件\n";
        return;
    }
    std::vector<std::vector<std::string>> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream sin(line);
        std::vector<std::string> fields;
        std::string field;
        while (sin >> field) {
            fields.push_back(field);
        }
        lines.push_back(fields);
    }
    inFile.close();

    // 在这里修改lines的内容
    for (auto& fields : lines) {
        if (!fields.empty() && fields[0] == managename ) { // 找到用户名且确保有密码字段
            fields[0] = newmanagename;
            fields[1] = newpassword;  // 更改密码
        }
    }

    std::ofstream outFile("manage.txt");
    if (!outFile) {
        std::cerr << "无法打开输出文件\n";
        return;
    }

    // 把修改后的内容写回文件
    for (const auto& fields : lines) {
        for (size_t i = 0; i < fields.size(); ++i) {
            if (i > 0) {
                outFile << ' ';
            }
            outFile << fields[i];
        }
        outFile << '\n';
    }
}