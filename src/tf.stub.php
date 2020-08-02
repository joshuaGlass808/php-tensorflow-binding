<?php

/** @generate-function-entries */

class TFOperation {
    public function __construct() {}
    public function __destruct() {}
}

class TFOperationDescription {
    public function __construct() {}
    public function __destruct() {}
}

class TFInput {
    public function __construct() {}
    public function __destruct() {}
}

class TFOutput {
    public function __construct() {}
    public function __destruct() {}
}

class TFFuntion {
    public function __construct() {}
    public function __destruct() {}
}

class TFFunctionOperations {
    public function __construct() {}
    public function __destruct() {}
}

class TFGraph {
    public function __construct() {}
    public function __destruct() {}
    public function setTensorShape(
        TFOutput $output,
        int $dims, 
        int $numDims, 
        TFStatus $status
    ): void {}
}

class TFSessionOptions {
    public function __construct() {}
    public function __destruct() {}
    public function setTarget(string $target): void {}
}

class TFBuffer {
    public function __construct(?string $data = null) {}
    public function __destruct() {}
}

class TFStatus {
    public function __construct() {}
    public function __destruct() {}
    public function setStatusCode(int $errorCode, string $context): void {}
    public function getStatusMessage(): string {}

    /**
     * TF_OK = 0,
     * TF_CANCELLED = 1,
     * TF_UNKNOWN = 2,
     * TF_INVALID_ARGUMENT = 3,
     * TF_DEADLINE_EXCEEDED = 4,
     * TF_NOT_FOUND = 5,
     * TF_ALREADY_EXISTS = 6,
     * TF_PERMISSION_DENIED = 7,
     * TF_UNAUTHENTICATED = 16,
     * TF_RESOURCE_EXHAUSTED = 8,
     * TF_FAILED_PRECONDITION = 9,
     * TF_ABORTED = 10,
     * TF_OUT_OF_RANGE = 11,
     * TF_UNIMPLEMENTED = 12,
     * TF_INTERNAL = 13,
     * TF_UNAVAILABLE = 14,
     * TF_DATA_LOSS = 15,
     */
    public function getStatusCode(): int {}
}
