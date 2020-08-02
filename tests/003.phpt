--TEST--
Test out TF_Status
--SKIPIF--
<?php
if (!extension_loaded('tensorflow_binding')) {
	echo 'skip';
}
?>
--FILE--
<?php
$test = new TFStatus();
$test2 = new TFStatus();
$test->setStatusCode(2, 'Test');
$test2->setStatusCode(0, 'Test'); // Test will not be used because 0 = TF_OK
var_dump($test->getStatusCode(), $test->getStatusMessage(),$test2->getStatusCode(), $test2->getStatusMessage());
?>
--EXPECT--
int(2)
string(4) "Test"
int(0)
string(0) ""
