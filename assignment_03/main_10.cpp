#include <iostream>
#include <iomanip>
#include <string>

unsigned int str_length(std::string str) {
    unsigned int counter = 0;
    while (str[counter]) {
        counter++;
    }
    return counter;
}

int findHostname(std::string url) {
    int length = str_length(url);
    int counter = 0;
    int hostnameStart;
    bool startFound = false;

    while (!startFound) {
        if (url[counter] == '/') {
            hostnameStart = counter + 2;
            startFound = true;
        }
        counter++;
    }

    return hostnameStart;
}

int findEnd(std::string url, int indexStart) {
    int length = str_length(url);
    int counter = indexStart;
    int end;
    bool endFound = false;

    while (!endFound) {
        if ((url[counter] == '/') || (url[counter] == ':') || (counter == length)) {
            end = counter;
            endFound = true;
        }
        counter++;
    }

    return end;
}

int findSubdomain(std::string hostname, int length) {
    int endSub = -1;

    for (int i = 0; i < length - 4; i++) {
        if (hostname[i] == '.') {
            endSub = i;
        }
    }

    return endSub;
}

int main() {
    std::string url;
    std::string hostname;
    std::cin >> url;

    int indexStart = findHostname(url);
    int indexEnd = findEnd(url, indexStart);

    int hostnameLength = indexEnd - indexStart;
    hostname = url.substr(indexStart, hostnameLength);

    for (int i = 0; i < hostnameLength; i++) {
        hostname[i] = tolower(hostname[i]);
    }

    int endOfSubdomain = findSubdomain(hostname, hostnameLength);

    std::cout << hostname << std::endl;

    return 0;
}