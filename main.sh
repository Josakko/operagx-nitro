#!/bin/bash

curl --request POST \
  --url https://api.discord.gx.games/v1/direct-fulfillment \
  --header 'accept: /' \
  --header 'accept-language: en-US,en;q=0.9' \
  --header 'authority: api.discord.gx.games' \
  --header 'content-type: application/json' \
  --header 'origin: https://www.opera.com/' \
  --header 'referer: https://www.opera.com/' \
  --header 'sec-ch-ua: "Opera GX";v="105", "Chromium";v="119", "Not?A_Brand";v="24"' \
  --header 'sec-ch-ua-mobile: ?0' \
  --header 'sec-ch-ua-platform: "Windows"' \
  --header 'sec-fetch-dest: empty' \
  --header 'sec-fetch-mode: cors' \
  --header 'sec-fetch-site: cross-site' \
  --header 'user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36 OPR/105.0.0.0' \
  --data '{"partnerUserId":"fb4cf2a97651bb7265da5f316cccb46577ba4aa2653eefcae5e849bafdeeb585"}'