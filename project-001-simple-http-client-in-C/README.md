<h1>Minimal HTTP Client in C </h1>

This is only an implentation to deepen my knowleedge about sockets and HTTP protocol and only serves as proof of concept and nothing more,
I fairly enjoyed coding it in 45 mins
<h4> Compilation </h4>

```bash
gcc main.c -o simple-http-client
```


<h4> usage </h4>

```bash
./simple-http-client
usage: ./main $domain $port $method $path

./simple-http-client www.example.com 80 GET /
<INSERT <example> HTML CODE HERE>
```
  
