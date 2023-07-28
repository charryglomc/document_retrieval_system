#include "WordQuery.h"
#include "WordQueryServer.h"
#include "mylogger.h"
using std::stoi;
using namespace clp;

int main() {
    Configuration::getInstance(
        "/clp/project/document_retrieval_system/conf/online.conf");

    WordQueryServer server(stoi(CONFIG["threadNum"]), stoi(CONFIG["queSize"]),
                           CONFIG["ip"], stoi(CONFIG["port"]));

    server.start();

    Mylogger::destroy();
    return 0;
}