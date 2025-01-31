library library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Nmux is 
    generic (N : integer :=2)
    port (
        mux_in: IN std_logic_vector(N-1 downto 0);
        sel    : IN std_logic_vector(log(N) downto 0)
        mux_out: OUT std_logic);
    end Nmux;

architecture msss of Nmux is 
    begin
    for i in 0 to N-1 generate 
        if sel=i then mux_out<=mux_in(i)
    end generate
    end msss;
    