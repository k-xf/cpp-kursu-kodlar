#### atomic

- Threadler arasında veriyi paylaşırken "data race" oluşmaması için genellikle bir senkonizayon mekanizması gereklidir. (örneğin mutex kullanarak senkronizasyonu sağlamal).
- Atomic types are another mechanism for providing synchronized access to data.
- An operation that is indivisible is said to be atomic (i.e., no parts of any other operations can interleave with any part of an atomic operation).
- Most processors support atomic memory operations via special machine instructions.
- Atomic memory operations cannot result in torn reads or torn writes.
- The standard library offers the following types in order to provide support for atomic memory operations:
    - std::atomic_flag
    - std::atomic
- These types provide a uniform interface for accessing the atomic memory operations of the underlying hardware.
