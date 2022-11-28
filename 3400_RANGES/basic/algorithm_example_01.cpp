template<typename Iter, typename Init>
Init Accumulate1(Iter beg, Iter end, Init init)
{
	while (beg != end)
	{
		init = std::move(init) + *beg;
		++beg;
	}
	return init;
}

----------------------------------------------------------------------------------------------------
  
template<typename Iter, typename SenType, typename Init, typename Op = std::plus<>>
Init Accumulate2(Iter beg, SenType end, Init init, Op op = {})
{
	while (beg != end)
	{
		init = op(std::move(init), *beg);
		++beg;
	}
	return init;
}

----------------------------------------------------------------------------------------------------
  
  
template<typename Iter, typename SenType, typename Init, typename Op = std::plus<>>
requires std::input_iterator<Iter> && std::sentinel_for<Iter, SenType>
Init Accumulate3(Iter beg, SenType end, Init init, Op op = {})
{
	while (beg != end)
	{
		init = op(std::move(init), *beg);
		++beg;
	}
	return init;
}

----------------------------------------------------------------------------------------------------
  
template<std::input_iterator Iter, std::sentinel_for<Iter> SenType, typename Init, typename Op = std::plus<>>
Init Accumulate4(Iter beg, SenType end, Init init, Op op = {})
{
	while (beg != end)
	{
		init = op(std::move(init), *beg);
		++beg;
	}
	return init;
}

----------------------------------------------------------------------------------------------------
  
template<std::input_iterator Iter, std::sentinel_for<Iter> SenType, typename Init, typename Op = std::plus<>>
Init Accumulate5(Iter beg, SenType end, Init init, Op op = {})
{
	while (beg != end)
	{
		init = std::invoke(op, std::move(init), *beg);
		++beg;
	}
	return init;
}
  
----------------------------------------------------------------------------------------------------
  
template<std::input_iterator Iter, std::sentinel_for<Iter> SenType, typename Init = std::iter_value_t<Iter>, typename Op = std::plus<>>
Init Accumulate6(Iter beg, SenType end, Init init = Init{}, Op op = {})
{
	while (beg != end)
	{
		init = std::invoke(op, std::move(init), *beg);
		++beg;
	}
	return init;
}


----------------------------------------------------------------------------------------------------
	
	
template<std::input_iterator Iter, std::sentinel_for<Iter> SenType, typename Init = std::iter_value_t<Iter>, typename Op = std::plus<>, typename Proj = std::identity>
Init Accumulate7(Iter beg, SenType end, Init init = Init{}, Op op = {}, Proj proj = {})
{
	while (beg != end)
	{
		init = std::invoke(op, std::move(init), std::invoke(proj, *beg));
		++beg;
	}
	return init;
}

----------------------------------------------------------------------------------------------------

template<std::ranges::input_range R, class Init = std::ranges::range_value_t<R>, typename Op = std::plus<>, typename Proj = std::identity>
Init Accumulate(R &&r, Init init = Init{}, Op op = {}, Proj proj = {})
{
	return Accumulate(std::ranges::begin(r), std::ranges::end(r),std::move(init), std::move(op), std::move(proj)); 
}	
