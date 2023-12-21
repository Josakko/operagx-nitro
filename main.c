#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>


// set how many urls to generate before exiting
#define ITERATIONS 1000


size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    cJSON *json = cJSON_Parse(contents);
    
    if (json) {
        cJSON *token = cJSON_GetObjectItem(json, "token");
        if (token) {
            char *url = malloc(strlen("https://discord.com/billing/partner-promotions/1180231712274387115/") + strlen(token -> valuestring) + 1);
            sprintf(url, "https://discord.com/billing/partner-promotions/1180231712274387115/%s", token -> valuestring);
            printf("%s\n\n", url);
            free(url);
        }
        
        cJSON_Delete(json);
    }

    return realsize;
}


void send_req() {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        struct curl_slist *headers = NULL;

        const char *url = "https://api.discord.gx.games/v1/direct-fulfillment";
        const char *payload = "{\"partnerUserId\":\"fb4cf2a97651bb7265da5f316cccb46577ba4aa2653eefcae5e849bafdeeb585\"}";

        headers = curl_slist_append(headers, "authority: api.discord.gx.games");
        headers = curl_slist_append(headers, "accept: /");
        headers = curl_slist_append(headers, "accept-language: en-US,en;q=0.9");
        headers = curl_slist_append(headers, "content-type: application/json");
        headers = curl_slist_append(headers, "origin: https://www.opera.com/");
        headers = curl_slist_append(headers, "referer: https://www.opera.com/");
        headers = curl_slist_append(headers, "sec-ch-ua: \"Opera GX\";v=\"105\", \"Chromium\";v=\"119\", \"Not?A_Brand\";v=\"24\"");
        headers = curl_slist_append(headers, "sec-ch-ua-mobile: ?0");
        headers = curl_slist_append(headers, "sec-ch-ua-platform: \"Windows\"");
        headers = curl_slist_append(headers, "sec-fetch-dest: empty");
        headers = curl_slist_append(headers, "sec-fetch-mode: cors");
        headers = curl_slist_append(headers, "sec-fetch-site: cross-site");
        headers = curl_slist_append(headers, "user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36 OPR/105.0.0.0");

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "sending request failed!\n");

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    for (int i = 0; i < ITERATIONS; ++i) {
        send_req();
    }

    return 0;
}

