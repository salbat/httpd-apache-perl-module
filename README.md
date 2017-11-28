# httpd-apache-perl-module
httpd/Apache2 Module in Perl

Download and extract httpd2.2:
```bash
curl -O https://archive.apache.org/dist/httpd/httpd-2.2.11.tar.gz
tar zxvf httpd-2.2.11.tar.gz
```

Download and extract mod_perl-2.0.10:
```bash
curl -O http://apache.mirror.amaze.com.au/perl/mod_perl-2.0.10.tar.gz
tar xzvf mod_perl-2.0.10.tar.gz
```
Compile mod_perl:
```bash
sudo perl Makefile.PL MP_CCOPTS=-std=gnu89 MP_APXS=/usr/local/apache2/bin/apxs
make
sudo make install
```

Test httpd/mod_perl and verify CGI scripts:
```bash
sudo vim /usr/local/apache2/conf/httpd.conf

/usr/local/apache2/bin/apachectl configtest

sudo /usr/local/apache2/bin/apachectl start

telnet localhost 80

vim /usr/local/apache2/cgi-bin/

vim /usr/local/apache2/cgi-bin/test.pl

sudo chmod a+rx  /usr/local/apache2/cgi-bin/test.pl

ls /usr/local/apache2/cgi-bin

tail -f /usr/local/apache2/logs/error_log

chmod a+x /usr/local/apache2/cgi-bin/*

sudo vim /usr/local/apache2/cgi-bin/test.pl
```


Path of the `CurrentTime.pm` and all other scripts:
```bash
/usr/local/apache2/lib/perl/Apache/*.pm
```

#H2 Perl Module

#H2 C Module

Compile the C code:

```bash
CFLAGS="-O3" CXXFLAGS="-O3" ./configure -prefix=/usr/local/apache2 -enable-autoindex -enable-cache -enable-cgi -enable-deflate -enable-dir -enable-disk_cache -enable-fastcgi -enable-file_cache -enable-headers -enable-include -enable-info -enable-log_config -enable-log_forensic -enable-logio -enable-mem_cache -enable-mime -enable-mime_magic -enable-negotiation -enable-perl -enable-proxy -enable-proxy-balancer -enable-proxy-http -enable-rewrite -enable-speling -enable-status -enable-suexec -enable-userdir -enable-usertrack -enable-version -enable-vhost_alias -enable-so -enable-mods-shared=all --enable--hello

make

sudo make install

```

Add the module to the `httpd.conf`:

```xml
<Location "/hello-c-module">                                                                        SetHandler hello                                                                            </Location> 
```