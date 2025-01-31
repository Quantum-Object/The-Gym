library ieee;
use ieee.1164.all;
use ieee.numeric_std.all;

entity FourBitMulti is 
port(
    -- max is 15*15=225 that need 8 bits;
    A,B: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    P : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
    clk: IN STD_LOGIC
);
end FourBitMulti;

architecture Behavioral of FourBitMulti is
architecture Behavioral of 4bitMulti is
    signal i: INTEGER range 0 to 3 := 0;
    signal BP: STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS=>'0');
begin
    BP <= "0000" & B;
    process(clk)
    begin
        BP <= "0000" & B;
        if rising_edge(clk) then
                P <= std_logic_vector(unsigned(P) + unsigned(BP));
                P <= P + BP;
            end if;
            i <= i + 1;
            BP <= BP(6 DOWNTO 0) & '0'; --shift one step left (*2) 
        end if;
    end process;
end Behavioral ;


--- another way I think 
architecture Behavioral of 4bitMulti is
    signal i: INTEGER range 0 to 3 := 0;
    signal R: STD_LOGIC_VECTOR(4 DOWNTO 0) := (OTHERS=>'0');
    begin
        process(clk)
            if rising_edge(clk)
                if A(i)='1' then
                    R <= R + B;
                else
                    R <= R;
                end IF;
                P(i) <= R(0);
                R(3 DOWNTO 0) <= R(4 DOWNTO 1);
                R(4)<=R(3);
                i <= i+1;
                if i=4 then
                    P(7 downto 4) <=R(3 downto 0);
                end if;
            end if;

        end process;
        
end Behavioral;

---- ok again "allah is one who is going to help me cuz why
-- , I asked him to and he is the most generous.<3"





--- P : 000000000
--- B : 1010  , A=0110
--- R : 00000
-- so each time we add  B to R and then move R(0) to P(i) 
-- then i++; and R/2 aka shift right.


        

