-- Generated by re2hs
{-# LANGUAGE RecordWildCards #-}
-- re2hs $INPUT -o $OUTPUT -i
{-# LANGUAGE OverloadedStrings #-}
{-# OPTIONS_GHC -Wno-unused-record-wildcards #-}

import Data.ByteString (ByteString, index)

data S't''a'''t'e' = S't''a'''t'e' {
    _yyinput :: ByteString,
    _yycursor :: Int
}


yy0 :: S't''a'''t'e' -> Bool
yy0 S't''a'''t'e'{..} =
    let yych = index _yyinput _yycursor in
    let __ = _yycursor + 1 in let _yycursor = __ in
    case yych of
        _c | 0x31 <= _c && _c <= 0x39 ->
            yy2 S't''a'''t'e'{..}
        _c | True ->
            yy1 S't''a'''t'e'{..}

yy1 :: S't''a'''t'e' -> Bool
yy1 S't''a'''t'e'{..} =
    let _y' = '\n' in let _x'' = '\'' in let y' = False in y'

yy2 :: S't''a'''t'e' -> Bool
yy2 S't''a'''t'e'{..} =
    let yych = index _yyinput _yycursor in
    case yych of
        _c | 0x30 <= _c && _c <= 0x39 ->
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy2 S't''a'''t'e'{..}
        _c | True ->
            yy3 S't''a'''t'e'{..}

yy3 :: S't''a'''t'e' -> Bool
yy3 S't''a'''t'e'{..} =
    let _x' = '}' in let _x'' = '}' in let x'0'' = True in x'0''

l'''e'x''''e'r' :: S't''a'''t'e' -> Bool
l'''e'x''''e'r' S't''a'''t'e'{..} =
    yy0 S't''a'''t'e'{..}



main :: IO ()
main = case l'''e'x''''e'r' S't''a'''t'e'{_yyinput = "1234\0", _yycursor = 0} of
    True -> return ()
    False -> error "lexer failed!"
