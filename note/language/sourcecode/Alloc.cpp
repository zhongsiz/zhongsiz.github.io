allocator::value_type
allocator::pointer
allocator::const_pointer
allocator::reference
allocator::const_reference
allocator::size_type
allocator::difference_type
allocator::rebind
allocator::allocator()
allocator::allocator(const allocator&)
// generic copy constructor
template<class U>fe
allocator::allocator(const allocator<U>&)
allocator::~allocator()
pointer allocator::address(reference x) const
const_pointer allocator::address(const_reference x) const
pointer allocator::allocator(size_type n, const void* = 0)
void allocator::deallocator(pointer p, size_type n)
size_type allocator::max_size() const
void allocator::construct(pointer p, const T& x)
void allocator::destory(pointer p)

template <class T, class Alloc = alloc>
class vector { ... };
template <class Key,
    class Compare = less<Key>,
    class Alloc = alloc>
class set { ... };