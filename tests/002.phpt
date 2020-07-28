--TEST--
Create various classes.
--SKIPIF--
<?php
if (!extension_loaded('tensorflow_binding')) {
	echo 'skip';
}
?>
--FILE--
<?php
$test1 = new TFGraph();
$test2 = new TFSessionOptions();
$test3 = new TFBuffer();
$test4 = new TFBuffer('Test');

var_dump($test1, $test2, $test3, $test4);
?>
--EXPECT--
object(TFGraph)#1 (0) {
}
object(TFSessionOptions)#2 (0) {
}
object(TFBuffer)#3 (0) {
}
object(TFBuffer)#4 (0) {
}