#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;


typedef unsigned long long RequestId;

void printHeaders(const HeaderList& headers) {
    cout << "--- HTTP Headers ---" << endl;
    for (const Header& h : headers) {
        cout << "  " << h.first << ": " << h.second << endl;
    }
}

int main(){

    RequestId reqId = 1748293847ULL;
    Port serverPort = 8080;
    IPAddress serverIP = "192.168.1.105";

    HeaderList requestHeaders = {
        {"Content-Type", "application/json"},
        {"Authorization", "Bearer eyJhbGciOiJIUzI1Ni..."},
        {"User-Agent", "MicroserviceClient/2.4.0"},
        {"Accept", "*/*"}
    };

    cout << "Request ID : " << reqId << endl;
    cout << "Server     : " << serverPort << endl;

    printHeaders(requestHeaders);

    return 0;
}