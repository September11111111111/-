#include"handle.h"
void handle::borrow(const std::string& bookName) 
{
    std::ifstream inFile("store.txt");
    if (!inFile) {
        std::cerr << "�޷��������ļ�\n";
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

    // �������޸�lines������
    for (auto& fields : lines) {
        if (!fields.empty() && fields[0] == bookName && fields.size() > 5 && fields[5] == "0") {
            fields[5] = "1";  // ��״̬��0����Ϊ1
        }
    }

    std::ofstream outFile("store.txt");
    if (!outFile) {
        std::cerr << "�޷�������ļ�\n";
        return;
    }

    // ���޸ĺ������д���ļ�
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
        std::cerr << "�޷��������ļ�\n";
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

    // �������޸�lines������
    for (auto& fields : lines) {
        if (!fields.empty() && fields[0] == bookName && fields.size() > 5 && fields[5] == "1") {
            fields[5] = "0";  // ��״̬��0����Ϊ1
        }
    }

    std::ofstream outFile("store.txt");
    if (!outFile) {
        std::cerr << "�޷�������ļ�\n";
        return;
    }

    // ���޸ĺ������д���ļ�
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
        std::cerr << "�޷��������ļ�\n";
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

    // �������޸�lines������
    for (auto& fields : lines) {
        if (!fields.empty() && fields[0] == userName && fields.size() > 2) { // �ҵ��û�����ȷ���������ֶ�
            fields[2] = newPassword;  // ��������
        }
    }

    std::ofstream outFile("student.txt");
    if (!outFile) {
        std::cerr << "�޷�������ļ�\n";
        return;
    }

    // ���޸ĺ������д���ļ�
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
        std::cerr << "�޷��������ļ�\n";
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

    // �������޸�lines������
    lines.erase(std::remove_if(lines.begin(), lines.end(),
        [&studentId](const std::vector<std::string>& fields) {
            return !fields.empty() && fields[0] == studentId;  // ɾ��ѧ��ƥ�����
        }), lines.end());

    std::ofstream outFile("student.txt");
    if (!outFile) {
        std::cerr << "�޷�������ļ�\n";
        return;
    }

    // ���޸ĺ������д���ļ�
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
        std::cerr << "�޷��������ļ�\n";
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

    // �������޸�lines������
    lines.erase(std::remove_if(lines.begin(), lines.end(),
        [&bookName](const std::vector<std::string>& fields) {
            return !fields.empty() && fields[0] == bookName;  // ɾ��ѧ��ƥ�����
        }), lines.end());

    std::ofstream outFile("store.txt");
    if (!outFile) {
        std::cerr << "�޷�������ļ�\n";
        return;
    }

    // ���޸ĺ������д���ļ�
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
        std::cerr << "�޷��������ļ�\n";
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

    // �������޸�lines������
    for (auto& fields : lines) {
        if (!fields.empty()&& fields[0]== rootbookName) { // �ҵ��û�����ȷ���������ֶ�
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
        std::cerr << "�޷�������ļ�\n";
        return;
    }

    // ���޸ĺ������д���ļ�
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
        std::cerr << "�޷��������ļ�\n";
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

    // �������޸�lines������
    for (auto& fields : lines) {
        if (!fields.empty() && fields[0] == managename ) { // �ҵ��û�����ȷ���������ֶ�
            fields[0] = newmanagename;
            fields[1] = newpassword;  // ��������
        }
    }

    std::ofstream outFile("manage.txt");
    if (!outFile) {
        std::cerr << "�޷�������ļ�\n";
        return;
    }

    // ���޸ĺ������д���ļ�
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