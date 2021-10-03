--TEST--
Creation of various classes.
--SKIPIF--
<?php
if (!extension_loaded('tensorflow_binding')) {
	echo 'skip';
}
?>
--FILE--
<?php
$graph = new TFGraph();
$sessionOptions = new TFSessionOptions();
$buffer = new TFBuffer();
$bufferInit = new TFBuffer('Test');

var_dump($graph, $sessionOptions, $buffer, $bufferInit);
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