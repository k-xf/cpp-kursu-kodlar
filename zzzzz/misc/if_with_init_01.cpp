if (status s = check(); s != status::success) {
	return s;
}

-------------------------------------------------------------------------------

// strm isminin scopu disindayiz
if (std::ofstream strm = getLogStrm(); coll.empty()) {
	strm << "<no data>\n";
} 
else {
	for (const auto& elem : coll) { 
		strm << elem << '\n';
	} 
} 
// strm isminin scopu disindayiz

-------------------------------------------------------------------------------

if (std::lock_guard<std::mutex> lg{collMutex}; !coll.empty()) {
	std::cout << coll.front() << '\n';
}

-------------------------------------------------------------------------------

if (std::lock_guard lg{collMutex}; !coll.empty()) {
	std::cout << coll.front() << '\n';
}

-------------------------------------------------------------------------------

{
	std::lock_guard<std::mutex> lg{collMutex};
	if (!coll.empty()) {
		std::cout << coll.front() << '\n';
	}
}

-------------------------------------------------------------------------------

if (std::lock_guard<std::mutex>{collMutex}; !coll.empty()) { 
	// nu noktada kilitli degil
	std::cout << coll.front() << '\n'; // - kilitli degil
} 

-------------------------------------------------------------------------------
std::map<std::string, int> coll;
//...
if (auto [pos,ok] = coll.insert({"new",42}); !ok) {
	// if insert failed, handle error using iterator pos: 
	const auto& [key,val] = *pos; 
	std::cout << "already there: " << key << '\n';
}

-------------------------------------------------------------------------------

using namespace std::filesystem;
//...
switch (path p(name); status(p).type()) { 
	case file_type::not_found:
		std::cout << p << " not found\n"; break;
	case file_type::directory: 
		std::cout << p << ":\n"; 
		for (auto& e : std::filesystem::directory_iterator(p)) { 
			std::cout << "- " << e.path() << '\n'; 
		}
		break; 
	default: 
		std::cout << p << " exists\n";
		break;
} 

-------------------------------------------------------------------------------
