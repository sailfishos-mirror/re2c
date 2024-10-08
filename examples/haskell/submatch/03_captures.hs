-- Generated by re2hs
{-# LANGUAGE RecordWildCards #-}
#1 "haskell/submatch/03_captures.re"
-- re2hs $INPUT -o $OUTPUT
{-# OPTIONS_GHC -Wno-unused-record-wildcards #-}
{-# LANGUAGE OverloadedStrings #-}

import Control.Monad (when)
import Data.ByteString (ByteString, index)
import Data.Word (Word8)

none :: Int
none = -1

data State = State {
    -- Final tag bindings available in semantic action.
    
#19 "haskell/submatch/03_captures.hs"

_yytl0 :: !Int,
_yytl1 :: !Int,
_yytl2 :: !Int,
_yytl3 :: !Int,
_yytr0 :: !Int,
_yytr1 :: !Int,
_yytr2 :: !Int,
_yytr3 :: !Int,
#14 "haskell/submatch/03_captures.re"

    -- Intermediate tag bindings used by the lexer (must be autogenerated).
    
#33 "haskell/submatch/03_captures.hs"

_yyt1 :: !Int,
_yyt2 :: !Int,
_yyt3 :: !Int,
_yyt4 :: !Int,
_yyt5 :: !Int,
#16 "haskell/submatch/03_captures.re"

    _yyinput :: !ByteString,
    _yycursor :: !Int,
    _yymarker :: !Int
}

data SemVer = SemVer {
    major :: !Int,
    minor :: !Int,
    patch :: !Int
} deriving (Eq)

s2n :: ByteString -> Int -> Int -> Int
s2n s i j = f i 0 where
    f k n = if k >= j then n else f (k + 1) (n * 10 + (fromIntegral (index s k) - 48))


#58 "haskell/submatch/03_captures.hs"
yy0 :: State -> Maybe SemVer
yy0 State{..} =
    let yych = index _yyinput _yycursor in
    case yych of
        _c | 0x30 <= _c && _c <= 0x39 ->
            let _yyt1 = _yycursor in
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy3 State{..}
        _c | True ->
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy1 State{..}

yy1 :: State -> Maybe SemVer
yy1 State{..} =
    yy2 State{..}

yy2 :: State -> Maybe SemVer
yy2 State{..} =
#48 "haskell/submatch/03_captures.re"
    Nothing
#79 "haskell/submatch/03_captures.hs"

yy3 :: State -> Maybe SemVer
yy3 State{..} =
    let _yymarker = _yycursor in
    let yych = index _yyinput _yycursor in
    case yych of
        _c | 0x2E == _c ->
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy4 State{..}
        _c | 0x30 <= _c && _c <= 0x39 ->
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy6 State{..}
        _c | True ->
            yy2 State{..}

yy4 :: State -> Maybe SemVer
yy4 State{..} =
    let yych = index _yyinput _yycursor in
    case yych of
        _c | 0x30 <= _c && _c <= 0x39 ->
            let _yyt2 = _yycursor in
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy7 State{..}
        _c | True ->
            yy5 State{..}

yy5 :: State -> Maybe SemVer
yy5 State{..} =
    let _yycursor = _yymarker in
    yy2 State{..}

yy6 :: State -> Maybe SemVer
yy6 State{..} =
    let yych = index _yyinput _yycursor in
    case yych of
        _c | 0x2E == _c ->
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy4 State{..}
        _c | 0x30 <= _c && _c <= 0x39 ->
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy6 State{..}
        _c | True ->
            yy5 State{..}

yy7 :: State -> Maybe SemVer
yy7 State{..} =
    let yych = index _yyinput _yycursor in
    case yych of
        _c | 0x00 == _c ->
            let _yyt3 = _yycursor in
            let _yyt4 = (-1) in
            let _yyt5 = (-1) in
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy8 State{..}
        _c | 0x2E == _c ->
            let _yyt3 = _yycursor in
            let _yyt5 = _yycursor in
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy9 State{..}
        _c | 0x30 <= _c && _c <= 0x39 ->
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy7 State{..}
        _c | True ->
            yy5 State{..}

yy8 :: State -> Maybe SemVer
yy8 State{..} =
    let _yytl1 = _yyt1 in
    let _yytl2 = _yyt2 in
    let _yytr2 = _yyt3 in
    let _yytl3 = _yyt5 in
    let _yytr3 = _yyt4 in
    let _yytl0 = _yyt1 in
    let _yytr0 = _yycursor in
    let _yytr1 = _yyt2 in
    let __ = if _yytr1 == (-1) then (-1) else _yytr1 - 1 in let _yytr1 = __ in
#41 "haskell/submatch/03_captures.re"
    Just SemVer {
        major = s2n _yyinput _yytl1 _yytr1,
        minor = s2n _yyinput _yytl2 _yytr2,
        patch = if _yytl3 == none then 0 else s2n _yyinput (_yytl3 + 1) _yytr3
    }
#162 "haskell/submatch/03_captures.hs"

yy9 :: State -> Maybe SemVer
yy9 State{..} =
    let yych = index _yyinput _yycursor in
    if yych <= 0x00 then yy5 State{..}
    else yy11 State{..} yych

yy10 :: State -> Maybe SemVer
yy10 State{..} =
    let yych = index _yyinput _yycursor in
    yy11 State{..} yych

yy11 :: State -> Word8 -> Maybe SemVer
yy11 State{..} yych =
    case yych of
        _c | 0x00 == _c ->
            let _yyt4 = _yycursor in
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy8 State{..}
        _c | 0x30 <= _c && _c <= 0x39 ->
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy10 State{..}
        _c | True ->
            yy5 State{..}

parse :: State -> Maybe SemVer
parse State{..} =
    yy0 State{..}

#49 "haskell/submatch/03_captures.re"


test :: ByteString -> Maybe SemVer -> IO ()
test str expect = do
    let s = State {
        
#199 "haskell/submatch/03_captures.hs"

_yytl0 = none,
_yytl1 = none,
_yytl2 = none,
_yytl3 = none,
_yytr0 = none,
_yytr1 = none,
_yytr2 = none,
_yytr3 = none,
#54 "haskell/submatch/03_captures.re"

        
#212 "haskell/submatch/03_captures.hs"

_yyt1 = none,
_yyt2 = none,
_yyt3 = none,
_yyt4 = none,
_yyt5 = none,
#55 "haskell/submatch/03_captures.re"

        _yyinput = str,
        _yycursor = 0,
        _yymarker = 0
    }
    when (parse s /= expect) $ error "failed!"

main :: IO ()
main = do
    test "23.34\0" (Just SemVer {major = 23, minor = 34, patch = 0})
    test "1.2.99999\0" (Just SemVer {major = 1, minor = 2, patch = 99999})
    test "1.a\0" Nothing
