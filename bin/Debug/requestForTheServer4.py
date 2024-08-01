import requests
import json
url='http://localhost/MyMQTTServer/db_handler.php'

with open('url.txt','r') as f:
    data=f.read()

print("RUN")
print(url)

headers = {
    'Content-Type': 'application/json',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
}

temp={"x":data}
print(f"request:{temp}")

response = requests.post(url,data=temp)

if response.status_code == 200:
    print(f"response:{response.text}")
else:
    print(f"Failed to retrieve data: {response.status_code}")
