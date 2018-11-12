using System.Text.RegularExpressions;

namespace Validation
{
    public class SimpleValidator : ISimpleValidator
    {
        public bool ContainsDigit(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return new Regex(@"\d").IsMatch(str);
        }

        public bool ContainsLowwerCharacter(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return new Regex(@"[a-z]").IsMatch(str);
        }

        public bool ContainsUpperCharacter(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return new Regex(@"[A-Z]").IsMatch(str);
        }

        public bool ContainsSpecialCharacter(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return new Regex(@"[!&*@%№|~$()?><}{-]").IsMatch(str);
        }

        public bool IsOnlyDigit(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return new Regex(@"^[\d]+$").IsMatch(str);
        }

        public bool StartsFromDigit(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return char.IsDigit(str[0]);
        }

        public bool IsLowerCase(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return new Regex(@"^[a-z]+$").IsMatch(str);
        }

        public bool IsUpperCase(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return new Regex(@"^[A-Z]+$").IsMatch(str);
        }

        public bool MatchesRegExp(string str, string match)
        {
            if (string.IsNullOrEmpty(str) || string.IsNullOrEmpty(match))
            {
                return false;
            }
            return new Regex(match).IsMatch(str);
        }

        public bool MoreThanMinLength(string str, uint minlen)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return str.Length >= minlen;
        }

        public bool LessThanMaxLength(string str, uint maxlen)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return str.Length <= maxlen;
        }

        public bool LenBeetwen(string str, uint min, uint max)
        {
            if (string.IsNullOrEmpty(str) || min > max)
            {
                return false;
            }
            return LessThanMaxLength(str, max) && MoreThanMinLength(str, min);
        }
    }
}
