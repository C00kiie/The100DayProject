<h1> project 004: server-status-monitor </h1>

 monitors /server-status and save the entries to a file, it came in handy in one of my penteration tests so I decided to finalize it and add a pretty cli to it as well

<h4> usage </h4>

```bash

$ python3 monitor-server-status.py https://playbill.com/server-status/ --output logfile.txt --interval 20
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 GET /images/photo/g/l/glenn200.jpg HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 GET /images/photo/u/s/ustinov2.jpg HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 GET /production/hadestown HTTP/1.1
 [*] 127.0.0.1 localhost:80 GET /article/revisit-60-years-of-theaterworksusa-with-daphne-ru
 [*] 127.0.0.1 localhost:80 GET /pagead/images/adchoices/icon.png HTTP/1.1
 [*] 127.0.0.1 localhost:80 GET /server-status/ HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 GET /article/mraid.js HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 GET /news/article/192651-STAGE-VIEWS-Chicago-Fire-and-Becket-St
 [*] 127.0.0.1 localhost:80 GET /images/photo/N/i/Nicole.jpg HTTP/1.1
 [*] 127.0.0.1 localhost:80 GET /news/article/188951-London-Festival-of-Cabaret-to-Return-i
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
 [*] 127.0.0.1 localhost:80 GET /news/article/93458-Tony-Winning-Light-in-the-Piazza-Extend
 [*] 127.0.0.1 localhost:80 POST /_track HTTP/1.1
```
