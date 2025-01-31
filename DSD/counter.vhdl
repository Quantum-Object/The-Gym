library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


ENTITY counter IS
Generic ( N: integer:= 4 );
PORT ( L, CLK: IN STD_LOGIC;
      q: BUFFER STD_LOGIC_VECTOR ( N-1 DOWNTO 0 ));
END counter


Architecture arch of counter IS

Signal in_qt : STD_LOGIC_VECTOR ( N-1 DOWNTO 0 ); --for transfering 
Signal in_muxout: STD_LOGIC_VECTOR ( N-2 DOWNTO 0); --for input of the mux

Begin

G1: for i IN N-1 DOWNTO 0 GENERATE 
    G2: IF i=N-1 GENERATE
        StageIf: TFF PORT MAP('1',clk, q(i), in_qt(i)); 
    END GENERATE
    G3: IF i<N-1 GENERATE 
        Muxes: MUX port map(in_qt(i+1), q(i+1),L,in_muxout(i));
        TFFs: TFF port map ('1',in_muxout(i),q(i),in_qt(i));
    END GENERATE
END GENERATE 
End arch
