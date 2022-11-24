#include <set>
#include <type_traits>
#include <concepts>

template<class T>
std::set<T> operator+(const std::set<T>& s1, const std::set<T>& s2)
{
  auto s = s1;
  for (const auto& e : s2)
    s.insert(e);

  return s;
}

template<class T>
std::set<T> operator-(const std::set<T>& s1, const std::set<T>& s2)
{
  auto s = s1;
  for (const auto& e : s2)
    s.erase(e);

  return s;
}

template<class T>
std::set<T> operator^(const std::set<T>& s1, const std::set<T>& s2)
{
  auto s = s1;
  for (const auto& e : s2)
  {
    if (s.find(e) != s.end())
      s.erase(e);
    else
      s.insert(e);
  }

  return s;
}

template<class T>
std::set<T> operator*(const std::set<T>& s1, const std::set<T>& s2)
{
  auto s = std::set<T>{};
  for (const auto& e1 : s1)
  {
    for (const auto& e2 : s2)
    {
      s.insert(e1 + e2);
    }
  }

  return s;
}

template<class T>
std::set<T> operator^(const std::set<T>& s1, int n)
{
  if (n == 0)
    return {};

  auto s = s1;
  while (n >= 2)
  {
    s = s * s1;
    n--;
  }

  return s;
}
