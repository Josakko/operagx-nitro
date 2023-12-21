import requests


ITERATIONS = 1000

def main():
    payload = "{\"partnerUserId\":\"fb4cf2a97651bb7265da5f316cccb46577ba4aa2653eefcae5e849bafdeeb585\"}"

    headers = {
        'authority': "api.discord.gx.games",
        'accept': "/",
        'accept-language': "en-US,en;q=0.9",
        'content-type': "application/json",
        'origin': "https://www.opera.com/",
        'referer': "https://www.opera.com/",
        'sec-ch-ua': '"Opera GX";v="105", "Chromium";v="119", "Not?A_Brand";v="24"',
        'sec-ch-ua-mobile': "?0",
        'sec-ch-ua-platform': '"Windows"',
        'sec-fetch-dest': "empty",
        'sec-fetch-mode': "cors",
        'sec-fetch-site': "cross-site",
        'user-agent': "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36 OPR/105.0.0.0"
        }


    f = open("urls.txt", "a", encoding="utf8")

    for _ in range(ITERATIONS):
        res = requests.post("https://api.discord.gx.games/v1/direct-fulfillment", headers=headers, data=payload)
        token = res.json()["token"]

        url = f"https://discord.com/billing/partner-promotions/1180231712274387115/{token}"
        #url = f"https://discord.com/billing/partner-promotions/1180231712274387115/eyJhbGciOiJkaXIiLCJlbmMiOiJBMjU2R0NNIn0..{token.split('..')[1]}"

        f.write(url + "\n\n")



main()
