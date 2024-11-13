#ifndef BRAM_HPP
#define BRAM_HPP

#include <systemc>
#include <tlm>
#include <tlm_utils/simple_target_socket.h>
#include <fstream>
#include "message.hpp"

// BRAM modul simulira blok RAM komponentu
class BRAM : public sc_core::sc_module {
public:
    tlm_utils::simple_target_socket<BRAM> socket;

    sc_core::sc_in<bool> en_b;
    sc_core::sc_in<sc_dt::uint64> addr_b;
    sc_core::sc_in<unsigned char> din_b[3];
    sc_core::sc_out<unsigned char> dout_b[3];
    sc_core::sc_in<bool> reset_b;
    sc_core::sc_in<bool> we_b;
    sc_core::sc_in<bool> clk_b;

    SC_CTOR(BRAM) : socket("socket"), en_b("en_b"), addr_b("addr_b"), reset_b("reset_b"), we_b("we_b"), clk_b("clk_b"), memory(nullptr) {
        socket.register_b_transport(this, &BRAM::b_transport);
        SC_THREAD(wire_b_transport);
        sensitive << clk_b.pos();
    }

    ~BRAM();

    // Metoda za postavljanje dimenzija slike i inicijalizaciju memorije
    void set_dimensions(int height, int width);
    
    // Metoda za ispis sadržaja BRAM memorije radi provere
    void print_memory_contents();

    // Metoda za pisanje sadržaja BRAM memorije u fajl
    void write_memory_to_file(const std::string& filename);

    // Metoda za pisanje sadržaja BRAM memorije u drugi fajl
    void write_processed_memory_to_file(const std::string& filename);

private:
    // Metoda za obradu transakcija
    void b_transport(tlm::tlm_generic_payload& trans, sc_core::sc_time& delay);
    void wire_b_transport();

    // Metoda za inicijalizaciju memorije nakon postavljanja dimenzija
    void initialize_memory();

    unsigned char* memory; // Memorija data za sliku
    int img_height, img_width;
};

#endif // BRAM_HPP

