// Forward declarations

template <typename> class set;

#if !defined(__forward__) && !defined(__nobb__data__set__h)
#define __nobb__data__set__h

template <typename type> class set
{
  // Settings

  static constexpr size_t first_alloc = 16;

  // Service nested classes

  template <typename ctype> struct valid
  {
    template <typename vtype> struct helper
    {
    };

    template <typename vtype> static uint8_t sfinae(...);
    template <typename vtype> static uint32_t sfinae(helper <decltype((* (const typename std :: remove_reference <vtype> :: type *) nullptr)((const type) {}))> *);

    static constexpr bool value = sizeof(sfinae <ctype> (0)) == sizeof(uint32_t);
  };

  // Members

  type * _items;
  size_t _size;
  size_t _alloc;

public:

  // Constructors

  set();

  // Destructor

  ~set();

  // Methods

  void add(const type &);
  void remove(const type &);

  template <typename lambda, typename std :: enable_if <valid <lambda> :: value> :: type * = nullptr> void each(const lambda &);
};

#endif
