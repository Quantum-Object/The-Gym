library ieee;
use ieee.std_logic_1164.all;

entity Comparator is 
port (
    A:IN STD_LOGIC_VECTOR(3 downto 0 );
    B:IN STD_LOGIC_VECTOR(3 downto 0 );
    L:OUT STD_LOGIC;--LESS
    G:OUT STD_LOGIC;--GREATER
    E:OUT STD_LOGIC-EQUALL
); END Comparator;

architecture rtl of compartor is
begin
   E<='1' when A=B else  '0';
   G<='1' when A>B else  '0';
   L<='1' when A<B else  '0';
end architecture rtl;