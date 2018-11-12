using System;

namespace Validation
{
    public interface ISimpleValidator
    {
        bool ContainsDigit(String str);
        bool ContainsSpecialCharacter(String str);
        bool IsOnlyDigit(String str);
        bool StartsFromDigit(String str);
        bool ContainsUpperCharacter(String str);
        bool ContainsLowwerCharacter(String str);
        bool IsLowerCase(String str);
        bool IsUpperCase(String str);
        bool MatchesRegExp(String str, String match);
        bool MoreThanMinLength(String str, uint minlen);
        bool LessThanMaxLength(String str, uint maxlen);
        bool LenBeetwen(String str, uint min, uint max);
    }
}