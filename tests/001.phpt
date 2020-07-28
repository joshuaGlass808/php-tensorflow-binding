--TEST--
Check if tensorflow_binding is loaded
--SKIPIF--
<?php
if (!extension_loaded('tensorflow_binding')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "tensorflow_binding" is available';
?>
--EXPECT--
The extension "tensorflow_binding" is available
