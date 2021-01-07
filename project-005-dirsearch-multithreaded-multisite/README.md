<h1> project 005: project-005-dirsearch-multithreaded-multisite </h1>

 brute force directories of multiple sites with 1 dictionary, for lazy late-night scanners
<h4> usage </h4>

```bash
./nito --help
usage: nito [-h] [--threads THREADS] [--timeout TIMEOUT] [--proxy PROXY] [--httpcodes HTTPCODES [HTTPCODES ...]] urls wordlist

Multi sites directory scanner, for lazy prople and latenight scans

positional arguments:
  urls                  urls file
  wordlist              the used wordlist to enumerate the urls

optional arguments:
  -h, --help            show this help message and exit
  --threads THREADS     number of Threads, default = 8
  --timeout TIMEOUT     Timeout period
  --proxy PROXY         use a proxy
  --httpcodes HTTPCODES [HTTPCODES ...]
                        List of http codes separated by spaces that you'd like to show up
 ./nito.py urls_list.txt dict --proxy http://127.0.0.1:8080 --threads 8 --httpcodes 200 403
zsh: no such file or directory: ./nito.py
./nito urls_list.txt dict --proxy http://127.0.0.1:8080 --threads 8 --httpcodes 200 403 
Found 4 valid urls
[*] https://www.facebook.com/cnn (200)
finished
```
