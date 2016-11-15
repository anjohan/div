% GNUPLOT: LaTeX picture with Postscript
\begingroup
  \makeatletter
  \providecommand\color[2][]{%
    \GenericError{(gnuplot) \space\space\space\@spaces}{%
      Package color not loaded in conjunction with
      terminal option `colourtext'%
    }{See the gnuplot documentation for explanation.%
    }{Either use 'blacktext' in gnuplot or load the package
      color.sty in LaTeX.}%
    \renewcommand\color[2][]{}%
  }%
  \providecommand\includegraphics[2][]{%
    \GenericError{(gnuplot) \space\space\space\@spaces}{%
      Package graphicx or graphics not loaded%
    }{See the gnuplot documentation for explanation.%
    }{The gnuplot epslatex terminal needs graphicx.sty or graphics.sty.}%
    \renewcommand\includegraphics[2][]{}%
  }%
  \providecommand\rotatebox[2]{#2}%
  \@ifundefined{ifGPcolor}{%
    \newif\ifGPcolor
    \GPcolortrue
  }{}%
  \@ifundefined{ifGPblacktext}{%
    \newif\ifGPblacktext
    \GPblacktextfalse
  }{}%
  % define a \g@addto@macro without @ in the name:
  \let\gplgaddtomacro\g@addto@macro
  % define empty templates for all commands taking text:
  \gdef\gplbacktext{}%
  \gdef\gplfronttext{}%
  \makeatother
  \ifGPblacktext
    % no textcolor at all
    \def\colorrgb#1{}%
    \def\colorgray#1{}%
  \else
    % gray or color?
    \ifGPcolor
      \def\colorrgb#1{\color[rgb]{#1}}%
      \def\colorgray#1{\color[gray]{#1}}%
      \expandafter\def\csname LTw\endcsname{\color{white}}%
      \expandafter\def\csname LTb\endcsname{\color{black}}%
      \expandafter\def\csname LTa\endcsname{\color{black}}%
      \expandafter\def\csname LT0\endcsname{\color[rgb]{1,0,0}}%
      \expandafter\def\csname LT1\endcsname{\color[rgb]{0,1,0}}%
      \expandafter\def\csname LT2\endcsname{\color[rgb]{0,0,1}}%
      \expandafter\def\csname LT3\endcsname{\color[rgb]{1,0,1}}%
      \expandafter\def\csname LT4\endcsname{\color[rgb]{0,1,1}}%
      \expandafter\def\csname LT5\endcsname{\color[rgb]{1,1,0}}%
      \expandafter\def\csname LT6\endcsname{\color[rgb]{0,0,0}}%
      \expandafter\def\csname LT7\endcsname{\color[rgb]{1,0.3,0}}%
      \expandafter\def\csname LT8\endcsname{\color[rgb]{0.5,0.5,0.5}}%
    \else
      % gray
      \def\colorrgb#1{\color{black}}%
      \def\colorgray#1{\color[gray]{#1}}%
      \expandafter\def\csname LTw\endcsname{\color{white}}%
      \expandafter\def\csname LTb\endcsname{\color{black}}%
      \expandafter\def\csname LTa\endcsname{\color{black}}%
      \expandafter\def\csname LT0\endcsname{\color{black}}%
      \expandafter\def\csname LT1\endcsname{\color{black}}%
      \expandafter\def\csname LT2\endcsname{\color{black}}%
      \expandafter\def\csname LT3\endcsname{\color{black}}%
      \expandafter\def\csname LT4\endcsname{\color{black}}%
      \expandafter\def\csname LT5\endcsname{\color{black}}%
      \expandafter\def\csname LT6\endcsname{\color{black}}%
      \expandafter\def\csname LT7\endcsname{\color{black}}%
      \expandafter\def\csname LT8\endcsname{\color{black}}%
    \fi
  \fi
    \setlength{\unitlength}{0.0500bp}%
    \ifx\gptboxheight\undefined%
      \newlength{\gptboxheight}%
      \newlength{\gptboxwidth}%
      \newsavebox{\gptboxtext}%
    \fi%
    \setlength{\fboxrule}{0.5pt}%
    \setlength{\fboxsep}{1pt}%
\begin{picture}(9360.00,8640.00)%
    \gplgaddtomacro\gplbacktext{%
      \csname LTb\endcsname%
      \put(1078,5270){\makebox(0,0)[r]{\strut{}$\num{-2}$}}%
      \put(1078,5886){\makebox(0,0)[r]{\strut{}$\num{-1.5}$}}%
      \put(1078,6502){\makebox(0,0)[r]{\strut{}$\num{-1}$}}%
      \put(1078,7117){\makebox(0,0)[r]{\strut{}$\num{-0.5}$}}%
      \put(1078,7733){\makebox(0,0)[r]{\strut{}$\num{0}$}}%
      \put(1210,4804){\makebox(0,0){\strut{}$\num{0e+00}$}}%
      \put(2747,4804){\makebox(0,0){\strut{}$\num{5e+04}$}}%
      \put(4283,4804){\makebox(0,0){\strut{}$\num{1e+05}$}}%
    }%
    \gplgaddtomacro\gplfronttext{%
      \csname LTb\endcsname%
      \put(176,6501){\rotatebox{-270}{\makebox(0,0){\strut{}$\langle E\rangle/L^2$}}}%
      \put(2746,4474){\makebox(0,0){\strut{}Iteration cycles}}%
      \put(2746,8309){\makebox(0,0){\strut{}\textbf{Energy}}}%
      \csname LTb\endcsname%
      \put(3296,5417){\makebox(0,0)[r]{\strut{}$T=1$}}%
      \csname LTb\endcsname%
      \put(3296,5197){\makebox(0,0)[r]{\strut{}$T=\num{2.4}$}}%
    }%
    \gplgaddtomacro\gplbacktext{%
      \csname LTb\endcsname%
      \put(6022,5024){\makebox(0,0)[r]{\strut{}$\num{1e-16}$}}%
      \put(6022,5393){\makebox(0,0)[r]{\strut{}$\num{1e-14}$}}%
      \put(6022,5763){\makebox(0,0)[r]{\strut{}$\num{1e-12}$}}%
      \put(6022,6132){\makebox(0,0)[r]{\strut{}$\num{1e-10}$}}%
      \put(6022,6502){\makebox(0,0)[r]{\strut{}$\num{1e-08}$}}%
      \put(6022,6871){\makebox(0,0)[r]{\strut{}$\num{1e-06}$}}%
      \put(6022,7240){\makebox(0,0)[r]{\strut{}$\num{0.0001}$}}%
      \put(6022,7610){\makebox(0,0)[r]{\strut{}$\num{0.01}$}}%
      \put(6022,7979){\makebox(0,0)[r]{\strut{}$\num{1}$}}%
      \put(6154,4804){\makebox(0,0){\strut{}$\num{0e+00}$}}%
      \put(7559,4804){\makebox(0,0){\strut{}$\num{5e+04}$}}%
      \put(8963,4804){\makebox(0,0){\strut{}$\num{1e+05}$}}%
    }%
    \gplgaddtomacro\gplfronttext{%
      \csname LTb\endcsname%
      \put(4856,6501){\rotatebox{-270}{\makebox(0,0){\strut{}$C_V/L^2$}}}%
      \put(7558,4474){\makebox(0,0){\strut{}Iteration cycles}}%
      \put(7558,8309){\makebox(0,0){\strut{}\textbf{Heat capacity}}}%
      \csname LTb\endcsname%
      \put(7976,5417){\makebox(0,0)[r]{\strut{}$T=1$}}%
      \csname LTb\endcsname%
      \put(7976,5197){\makebox(0,0)[r]{\strut{}$T=\num{2.4}$}}%
    }%
    \gplgaddtomacro\gplbacktext{%
      \csname LTb\endcsname%
      \put(946,704){\makebox(0,0)[r]{\strut{}$\num{0}$}}%
      \put(946,1241){\makebox(0,0)[r]{\strut{}$\num{0.2}$}}%
      \put(946,1779){\makebox(0,0)[r]{\strut{}$\num{0.4}$}}%
      \put(946,2316){\makebox(0,0)[r]{\strut{}$\num{0.6}$}}%
      \put(946,2854){\makebox(0,0)[r]{\strut{}$\num{0.8}$}}%
      \put(946,3391){\makebox(0,0)[r]{\strut{}$\num{1}$}}%
      \put(1078,484){\makebox(0,0){\strut{}$\num{0e+00}$}}%
      \put(2681,484){\makebox(0,0){\strut{}$\num{5e+04}$}}%
      \put(4283,484){\makebox(0,0){\strut{}$\num{1e+05}$}}%
    }%
    \gplgaddtomacro\gplfronttext{%
      \csname LTb\endcsname%
      \put(176,2182){\rotatebox{-270}{\makebox(0,0){\strut{}$\langle\abs{M}\rangle/L^2$}}}%
      \put(2680,154){\makebox(0,0){\strut{}Iteration cycles}}%
      \put(2680,3990){\makebox(0,0){\strut{}\textbf{Magnetisation}}}%
      \csname LTb\endcsname%
      \put(3296,1097){\makebox(0,0)[r]{\strut{}$T=1$}}%
      \csname LTb\endcsname%
      \put(3296,877){\makebox(0,0)[r]{\strut{}$T=\num{2.4}$}}%
    }%
    \gplgaddtomacro\gplbacktext{%
      \csname LTb\endcsname%
      \put(6022,704){\makebox(0,0)[r]{\strut{}$\num{1e-16}$}}%
      \put(6022,1032){\makebox(0,0)[r]{\strut{}$\num{1e-14}$}}%
      \put(6022,1361){\makebox(0,0)[r]{\strut{}$\num{1e-12}$}}%
      \put(6022,1689){\makebox(0,0)[r]{\strut{}$\num{1e-10}$}}%
      \put(6022,2018){\makebox(0,0)[r]{\strut{}$\num{1e-08}$}}%
      \put(6022,2346){\makebox(0,0)[r]{\strut{}$\num{1e-06}$}}%
      \put(6022,2675){\makebox(0,0)[r]{\strut{}$\num{0.0001}$}}%
      \put(6022,3003){\makebox(0,0)[r]{\strut{}$\num{0.01}$}}%
      \put(6022,3332){\makebox(0,0)[r]{\strut{}$\num{1}$}}%
      \put(6022,3660){\makebox(0,0)[r]{\strut{}$\num{100}$}}%
      \put(6154,484){\makebox(0,0){\strut{}$\num{0e+00}$}}%
      \put(7559,484){\makebox(0,0){\strut{}$\num{5e+04}$}}%
      \put(8963,484){\makebox(0,0){\strut{}$\num{1e+05}$}}%
    }%
    \gplgaddtomacro\gplfronttext{%
      \csname LTb\endcsname%
      \put(4856,2182){\rotatebox{-270}{\makebox(0,0){\strut{}$\chi/L^2$}}}%
      \put(7558,154){\makebox(0,0){\strut{}Iteration cycles}}%
      \put(7558,3990){\makebox(0,0){\strut{}\textbf{Magnetic susceptibility}}}%
      \csname LTb\endcsname%
      \put(7976,1097){\makebox(0,0)[r]{\strut{}$T=1$}}%
      \csname LTb\endcsname%
      \put(7976,877){\makebox(0,0)[r]{\strut{}$T=\num{2.4}$}}%
    }%
    \gplbacktext
    \put(0,0){\includegraphics{2by2}}%
    \gplfronttext
  \end{picture}%
\endgroup
