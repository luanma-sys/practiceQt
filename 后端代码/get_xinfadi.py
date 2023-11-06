import requests

def getjson():
    big_list=[]

    for i in range(1,11):
        data = {'limit': 20,
                'current': i,
                'pubDateStartTime': '',
                'pubDateEndTime': '',
                'prodPcatid': '',
                'prodCatid':'',
                'prodName':''
                }
        headers={'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.5112.102 Safari/537.36 Edg/104.0.1293.70'}

        url = 'http://www.xinfadi.com.cn/getPriceData.html'
        resp = requests.post(url=url, headers=headers, data=data)
        json_data = resp.json()
        data_list = json_data.get("list")
        
        big_list.append(data_list)
        
    return big_list


