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