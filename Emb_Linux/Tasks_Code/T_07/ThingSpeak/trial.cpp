#include <iostream>
#include <curl/curl.h>
#include <array>
#include<unistd.h>

int main() {
    CURL *curl;
    CURLcode res;

    // Replace with your ThingSpeak API key and field number
    const char* apiKey = "XGLJC1Y88Y0RC11U";
    int fieldNumber = 1; // Field to update (1-8)
    float data = 40.5;   // Data to send
    std::array<int,3> data_2;
    for(auto &i:data_2)
    {
        std::cin>>i;
    }
    for(auto i=0;i<3;i++)
    {
            // Create the URL for the ThingSpeak API
    std::string url = "https://api.thingspeak.com/update?api_key=" + std::string(apiKey) +
    "&field" + std::to_string(fieldNumber) + "=" + std::to_string(data_2[i]);

 // Initialize libcurl
 curl = curl_easy_init();
 if (curl) {
     // Set the URL
     curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

     // Perform the request
     res = curl_easy_perform(curl);

     // Check for errors
     if (res != CURLE_OK) {
         std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << "\n";
     } else {
         std::cout << "Data sent to ThingSpeak successfully! Value: " << data_2[i] << "\n";
     }

     // Cleanup
     curl_easy_cleanup(curl);
 } else {
     std::cerr << "Failed to initialize libcurl\n";
     return 1; // Exit if libcurl initialization fails
 }
sleep(5);
    }
    // // Create the URL for the ThingSpeak API
    // std::string url = "https://api.thingspeak.com/update?api_key=" + std::string(apiKey) +
    //                   "&field" + std::to_string(fieldNumber) + "=" + std::to_string(data);

    // // Initialize libcurl
    // curl = curl_easy_init();
    // if (curl) {
    //     // Set the URL
    //     curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    //     // Perform the request
    //     res = curl_easy_perform(curl);

    //     // Check for errors
    //     if (res != CURLE_OK) {
    //         std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << "\n";
    //     } else {
    //         std::cout << "Data sent to ThingSpeak successfully!\n";
    //     }

    //     // Cleanup
    //     curl_easy_cleanup(curl);
    // } else {
    //     std::cerr << "Failed to initialize libcurl\n";
    // }

    return 0;
}