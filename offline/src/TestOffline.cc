#include "DirScanner.h"
#include "PageLib.h"
#include "PageLibPreprocessor.h"
#include "tinyxml2.h"
using namespace clp;
using namespace tinyxml2;

int main() {
    Configuration::getInstance(
        "/clp/project/document_retrieval_system/offline/conf/offline.conf");
    DirScanner scanner;
    scanner();
    PageLib pagelib(scanner);
    pagelib.create();

    PageLibPreprocessor processer;
    processer.doProcess();

    return 0;
}