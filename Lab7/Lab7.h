#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		unsigned int size;

		// min size
		if (keys.size() < values.size())
		{
			size = keys.size();
		}
		else
		{
			size = values.size();
		}

		if (size > 0)
		{
			for (unsigned int i = 0; i < size; i++)
			{
				if (m.find(keys[i]) == m.end())
				{
					m.insert(std::pair<K, V>(keys[i], values[i]));
				}
			}
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		typedef std::map<K, V>::const_iterator const_iterator;
		
		for (const_iterator it = m.begin(); it != m.end(); it++)
		{
			v.push_back(it->first);
		}

		return v;
	}
		
	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		typedef std::map<K, V>::const_iterator const_iterator;

		for (const_iterator it = m.begin(); it != m.end(); it++)
		{
			v.push_back(it->second);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		typedef std::vector<T>::const_reverse_iterator const_reverse_iterator;

		for (const_reverse_iterator it = v.rbegin(); it != v.rend(); it++)
		{
			rv.push_back(*it);
		}

		return rv;
	}
}

template <typename T>
std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
{
	std::vector<T> combined;
	typedef std::vector<T>::const_iterator const_iterator;

	if (v1.size() > 0)
	{
		for (const_iterator it1 = v1.begin(); it1 != v1.end(); it1++)
		{
			bool bExist = false;

			for (const_iterator itc = combined.begin(); itc != combined.end(); itc++)
			{
				if (*it1 == *itc)
				{
					bExist = true;
				}
			}

			if (bExist == false)
			{
				combined.push_back(*it1);
			}
		}
	}

	if (v2.size() > 0)
	{
		if (v1.size() > 0)
		{
			for (const_iterator it2 = v2.begin(); it2 != v2.end(); it2++)
			{
				bool bExist = false;

				// search ovelapped
				for (const_iterator itc = combined.begin(); itc != combined.end(); itc++)
				{
					if (*itc == *it2)
					{
						bExist = true;
					}
				}

				if (bExist == false)
				{
					combined.push_back(*it2);
				}
			}
		}
		else
		{
			for (const_iterator it2 = v2.begin(); it2 != v2.end(); it2++)
			{
				combined.push_back(*it2);
			}
		}
	}

	return combined;
}

template <typename K, class V>
std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
{
	// add m1
	std::map<K, V> combined(m1);
	typedef std::map<K, V>::const_iterator constit;

	// add m2
	for (constit cit = m2.begin(); cit != m2.end(); cit++)
	{
		// search overlapped key at m2
		if (combined.find(cit->first) == combined.end())
		{
			// not existing key 
			combined.insert(std::pair<K, V>(cit->first, cit->second));
		}
	}

	return combined;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	typedef std::vector<T>::const_iterator constit;
	constit cit;

	// add m2
	for (cit = v.begin(); cit != v.end(); cit++)
	{
		os << *cit;
		
		if (cit != (v.end() - 1))
		{
			os << ", ";
		}
	}

	return os;
}

template <typename K, class V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
{
	typedef std::map<K, V>::const_iterator constit;
	constit cit;

	// add m2
	for (cit = m.begin(); cit != m.end(); cit++)
	{
		os << "{ " << cit->first << ", " << cit->second << " }" << std::endl;
	}

	return os;
}