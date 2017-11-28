# httpd-apache-perl-module
httpd/Apache2 Module in Perl

curl -O https://archive.apache.org/dist/httpd/httpd-2.2.11.tar.gz
10030  tar zxvf httpd-2.2.11.tar.gz\n
10031  cd httpd-2.2.11
curl -O http://apache.mirror.amaze.com.au/perl/mod_perl-2.0.10.tar.gz
tar xzvf mod_perl-2.0.10.tar.gz
sudo perl Makefile.PL MP_CCOPTS=-std=gnu89 MP_APXS=/usr/local/apache2/bin/apxs
make
sudo make install
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