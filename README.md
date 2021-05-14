# php-tensorflow-binding
## THIS IS NOT COMPLETE  /  READY FOR USE YET.
## JUST USING THIS AS A PLACE TO SAVE JUST IN CASE MY COMPUTER CRASHES :)
php tensorflow extension

to install:
- git clone repo.
- `cd php-tensorflow-binding`
- `phpize && ./configure && make -j4 && sudo make install`
- profit

Examples will come when this is complete.
But you could also look through the tests for some current usage examples:


```
<?php
// Constructing instances.
$test1 = new TFGraph();
$test2 = new TFSessionOptions();
$test3 = new TFBuffer();
$test4 = new TFBuffer('Test');
$status = new TFStatus();
$status2 = new TFStatus();
$status->setStatusCode(2, 'Test');
$status2->setStatusCode(0, 'Test'); // Test will not be used because 0 = TF_OK
var_dump($status->getStatusCode(), $status->getStatusMessage(),$status2->getStatusCode(), $status2->getStatusMessage());
```
