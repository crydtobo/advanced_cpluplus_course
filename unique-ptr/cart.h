#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Produkt
{
public:
    using Ptr = std::unique_ptr<Produkt>;
    Produkt(const std::string &n)
        : m_nazwa(n) {}
    const std::string &nazwa() const { return m_nazwa; }

private:
    std::string m_nazwa;
};

class Koszyk
{
public:
    size_t size() const { return m_produkty.size(); }
    auto begin() const { return m_produkty.cbegin(); }
    auto end() const { return m_produkty.cend(); }
    //const Produkt* front() const { return m_produkty.front(); }
    const Produkt* front() const { return m_produkty.front().get(); }

    /*!
     * Dodaje produkt do koszyka
     */
    //goly wskaznik
    Produkt* dodaj(std::unique_ptr<Produkt> p) {
        auto& result = m_produkty.emplace_back(std::move(p));
        return result.get(); 
    }

    /*!
     * Usuwa podany produkt z koszyka
     */
    Produkt::Ptr zabierz(Produkt *p) {
        auto found = std::find_if(m_produkty.begin(), m_produkty.end(), [p](auto &up){
            return p == up.get();
        });
        if(found == m_produkty.end())
            return nullptr;
            
        auto temp_up = std::move(*found);
        m_produkty.erase(found);
        return temp_up;
    }

    // /*!
    //  * Usuwa pierwszy produkt o podanej nazwie
    //  */
    // Produkt::Ptr zabierz(const std::string &n) {
    //     auto found = std::find_if(m_produkty.begin(), m_produkty.end(), [n](auto &it){
    //             return it->nazwa() == n;
    //     });
        
    //     if(found != m_produkty.end()){
    //         auto temp_up = std::move(*found);
    //         m_produkty.erase(found);
    //         return temp_up;
    //     }
    //     return nullptr;
    //     //throw std::runtime_error("TODO");
    // }

    /*!
     * Zwraca wskaźnik na pierwszy produkt o podanej nazwie
     */
    //goly wskaznik
    const Produkt *zobacz(const std::string &n) {
        auto found = std::find_if(m_produkty.begin(), m_produkty.end(), [n](auto &it){
                return it->nazwa() == n;
            });

        if(found != m_produkty.end()){
            return (*found).get();
        }
        return nullptr;
    }

private:
    std::vector<Produkt::Ptr> m_produkty;
};


/*
Moje dawid
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Produkt
{
public:
    Produkt(const std::string &n)
        : m_nazwa(n) {}
    const std::string &nazwa() const { return m_nazwa; }

private:
    std::string m_nazwa;
};

class Koszyk
{
public:
    size_t size() const { return m_produkty.size(); }
    auto begin() const { return m_produkty.cbegin(); }
    auto end() const { return m_produkty.cend(); }
    const Produkt* front() const { return m_produkty.front(); }
 
    void dodaj(Produkt *p) {
        if(p)
            m_produkty.push_back(p);
        else
            throw std::runtime_error("TODO");
    }
 
    bool zabierz(const Produkt *p) {
        if(p){
            auto found = std::find(m_produkty.begin(), m_produkty.end(), p);

            if(found != m_produkty.end()){
                m_produkty.erase(found);
            }
            else return false;
        }
        return true;
        //throw std::runtime_error("TODO");
    }
 
    bool zabierz(const std::string &n) {
            auto found = std::find_if(m_produkty.begin(), m_produkty.end(), [n](const auto it){
                return it->nazwa() == n;
            });
            if(found != m_produkty.end()){
                m_produkty.erase(found);
            }
            else{
                return false;
            }
        return true;
        //throw std::runtime_error("TODO");
    }
 
    const Produkt *zobacz(const std::string &n) {
        auto found = std::find_if(m_produkty.begin(), m_produkty.end(), [n](auto it){
                return it->nazwa() == n;
            });
            
        if(found != m_produkty.end()){
            return *found;
        }
        return nullptr;
        //throw std::runtime_error("TODO");
    }

private:
    std::vector<Produkt *> m_produkty;
};



*/