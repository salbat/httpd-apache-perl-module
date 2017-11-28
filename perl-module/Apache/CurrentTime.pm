#To access the module: http://localhost/time
package Apache::CurrentTime;

use strict;
use warnings;

use Apache2::RequestRec ();
use Apache2::RequestIO ();

use Apache2::Const -compile => qw(OK);

sub handler {
my $r = shift;

$r->content_type('text/plain');
$r->print("Current time is: " . scalar(localtime) . "\n");

return Apache2::Const::OK;
}
1;
