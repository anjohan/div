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
\begin{picture}(8640.00,8640.00)%
    \gplgaddtomacro\gplbacktext{%
      \csname LTb\endcsname%
      \put(1342,5024){\makebox(0,0)[r]{\strut{}$\num{0}$}}%
      \put(1342,5352){\makebox(0,0)[r]{\strut{}$\num{100000}$}}%
      \put(1342,5681){\makebox(0,0)[r]{\strut{}$\num{200000}$}}%
      \put(1342,6009){\makebox(0,0)[r]{\strut{}$\num{300000}$}}%
      \put(1342,6337){\makebox(0,0)[r]{\strut{}$\num{400000}$}}%
      \put(1342,6666){\makebox(0,0)[r]{\strut{}$\num{500000}$}}%
      \put(1342,6994){\makebox(0,0)[r]{\strut{}$\num{600000}$}}%
      \put(1342,7322){\makebox(0,0)[r]{\strut{}$\num{700000}$}}%
      \put(1342,7651){\makebox(0,0)[r]{\strut{}$\num{800000}$}}%
      \put(1342,7979){\makebox(0,0)[r]{\strut{}$\num{900000}$}}%
      \put(1734,4804){\makebox(0,0){\strut{}$\num{-800}$}}%
      \put(3036,4804){\makebox(0,0){\strut{}$\num{-700}$}}%
      \put(4338,4804){\makebox(0,0){\strut{}$\num{-600}$}}%
      \put(5640,4804){\makebox(0,0){\strut{}$\num{-500}$}}%
      \put(6941,4804){\makebox(0,0){\strut{}$\num{-400}$}}%
      \put(8243,4804){\makebox(0,0){\strut{}$\num{-300}$}}%
    }%
    \gplgaddtomacro\gplfronttext{%
      \csname LTb\endcsname%
      \put(176,6501){\rotatebox{-270}{\makebox(0,0){\strut{}Number of occurrences}}}%
      \put(4858,4474){\makebox(0,0){\strut{}$E$}}%
      \put(4858,8309){\makebox(0,0){\strut{}\textbf{Low temperature}}}%
      \csname LTb\endcsname%
      \put(7256,7806){\makebox(0,0)[r]{\strut{}$T=1$}}%
    }%
    \gplgaddtomacro\gplbacktext{%
      \csname LTb\endcsname%
      \put(1210,704){\makebox(0,0)[r]{\strut{}$\num{0}$}}%
      \put(1210,1197){\makebox(0,0)[r]{\strut{}$\num{5000}$}}%
      \put(1210,1689){\makebox(0,0)[r]{\strut{}$\num{10000}$}}%
      \put(1210,2182){\makebox(0,0)[r]{\strut{}$\num{15000}$}}%
      \put(1210,2675){\makebox(0,0)[r]{\strut{}$\num{20000}$}}%
      \put(1210,3167){\makebox(0,0)[r]{\strut{}$\num{25000}$}}%
      \put(1210,3660){\makebox(0,0)[r]{\strut{}$\num{30000}$}}%
      \put(1607,484){\makebox(0,0){\strut{}$\num{-800}$}}%
      \put(2935,484){\makebox(0,0){\strut{}$\num{-700}$}}%
      \put(4262,484){\makebox(0,0){\strut{}$\num{-600}$}}%
      \put(5589,484){\makebox(0,0){\strut{}$\num{-500}$}}%
      \put(6916,484){\makebox(0,0){\strut{}$\num{-400}$}}%
      \put(8243,484){\makebox(0,0){\strut{}$\num{-300}$}}%
    }%
    \gplgaddtomacro\gplfronttext{%
      \csname LTb\endcsname%
      \put(176,2182){\rotatebox{-270}{\makebox(0,0){\strut{}Number of occurrences}}}%
      \put(4792,154){\makebox(0,0){\strut{}$E$}}%
      \put(4792,3990){\makebox(0,0){\strut{}\textbf{High temperature}}}%
      \csname LTb\endcsname%
      \put(7256,3487){\makebox(0,0)[r]{\strut{}$T=\num{2.4}$}}%
    }%
    \gplbacktext
    \put(0,0){\includegraphics{probdist}}%
    \gplfronttext
  \end{picture}%
\endgroup
