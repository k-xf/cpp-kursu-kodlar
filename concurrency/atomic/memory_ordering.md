
#### acquire semantics
Yalnızca bellekten okuma _(load)_ işlemlerine yöneliktir. Bu işlemler yalın _load_ ya da _read-modify-write_ olabilir.
Acquire semantiği prevent memory reordering of the read-acquire with any read or write operation that follows it in program order.

Release semantics is a property that can only apply to operations that write to shared memory, whether they are read-modify-write operations or plain stores. 
The operation is then considered a write-release. 
Release semantics prevent memory reordering of the write-release with any read or write operation that precedes it in program order.
