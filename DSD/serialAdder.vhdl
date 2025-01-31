library ieee;
use ieee.std_logic_1164.all;


entity serialAdder is
    generic (N: integer :=4)
    port(
        reset, clk : IN STD_LOGIC;
        A,B: IN STD_LOGIC_VECTOR(N-1 downto 0);
        Sum : OUT STD_LOGIC_VECTOR(N downto 0);
    );

end serialAdder;

architecture bhv of serialAdder is
-- assume we have a dff and a full adder
component dff is
    port(
        clk : IN STD_LOGIC;
        D : IN STD_LOGIC;
        Q : OUT STD_LOGIC
    );
end component;

component fullAdder is
    port(
        A,B,Cin : IN STD_LOGIC;
        Sum,Cout : OUT STD_LOGIC
    );
end component;
begin
    process(clk)
    begin
        if rising_edge(clk) then
            if reset='1' then
                Sum <= (others=>'0');
            else
                for i in 0 to N-1 loop
                    fullAdder_inst : fullAdder port map(A(i),B(i),);
                end loop;
            end if;


        end if;
    end process;

