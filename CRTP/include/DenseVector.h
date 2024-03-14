namespace crtp
{
template <typename Derived>
class DenseVector
{
public:
    ~DenseVector();

    Derived &derived() { return static_cast<Derived &>(*this); }
    Derived const &derived() { return static_cast<Derived const &>(*this); }

    size_t size() const { return derived().size(); }

    decltype(auto) &operator[](size_t index) { return derived()[index]; }
    decltype(auto) const &operator[](size_t index) const { return derived()[index]; }

    decltype(auto) begin() { return derived().begin(); }
    decltype(auto) begin() const { return derived().begin(); }
    decltype(auto) end() { return derived().end(); }
    decltype(auto) end() const { return derived().end(); }

private:
    /* data */
};

}  // namespace crtp
