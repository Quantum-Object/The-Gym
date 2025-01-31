library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Comparator is
    port (
        A : in  STD_LOGIC_VECTOR(3 downto 0);  -- 4-bit input A
        B : in  STD_LOGIC_VECTOR(3 downto 0);  -- 4-bit input B
        L : out STD_LOGIC;                     -- Less than
        G : out STD_LOGIC;                     -- Greater than
        E : out STD_LOGIC                      -- Equal
    );
end Comparator;

architecture rtl of Comparator is
begin
    -- Equality Check
    E <= '1' when (A XOR B) = "0000" else '0';

    -- Greater Than Check
    G <= '1' when
            (A(3) AND NOT B(3)) = '1' or
            (A(2) AND NOT B(2) AND NOT (A(3) XOR B(3))) = '1' or
            (A(1) AND NOT B(1) AND NOT (A(3) XOR B(3)) AND NOT (A(2) XOR B(2))) = '1' or
            (A(0) AND NOT B(0) AND NOT (A(3) XOR B(3)) AND NOT (A(2) XOR B(2)) AND NOT (A(1) XOR B(1))) = '1'
        else '0';

    -- Less Than Check
    L <= '1' when
            (B(3) AND NOT A(3)) = '1' or
            (B(2) AND NOT A(2) AND NOT (A(3) XOR B(3))) = '1' or
            (B(1) AND NOT A(1) AND NOT (A(3) XOR B(3)) AND NOT (A(2) XOR B(2))) = '1' or
            (B(0) AND NOT A(0) AND NOT (A(3) XOR B(3)) AND NOT (A(2) XOR B(2)) AND NOT (A(1) XOR B(1))) = '1'
        else '0';
end rtl;
