#### std::shared_mutex

+ C++17 standartları ile eklendi.
+ _std::shared_mutex _iki ayrı erişim seviyesine sahip <br>
**paylaşımlı _(shared)_ :**  birden  fazla _thread_ aynı _mutex_'in sahipliğini paylaşabilir.<br>
exclusive - yalnızca bir thread mutex'e sahip olabilir<br>

Eğer bir _thread_, _exclusive lock_'ı edinmiş ise (sınıfın _lock_ ya da _try_lock_ fonksiyonlarından birine çağrı yaparak) başka _threadler_ kilidi edinemezler.
