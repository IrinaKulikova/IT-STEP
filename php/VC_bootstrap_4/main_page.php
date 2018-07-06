
<div class="container auto col-lg-12 mt-4 bg-secondary text-white">
    <div class="text-center">
        <h1>Generator CV</h1>
    </div>
    <form method="post">
        <fieldset id="comp_skills">
            <div class="container col-lg-12">
                <div class="row">
                    <div class="col-lg-4 mt-3">
                        <div class="form-group">
                            <div class="container">
                                <h4>Personal Information</h4>
                                <label for="first_name" class="mt-2">First Name *</label>
                                <input type="text" name="first_name" class="form-control" id="first_name" placeholder="First Name">
                                <label for="last_name" class="mt-2">Last Name *</label>
                                <input type="text" name="last_name"  class="form-control" id="last_name" placeholder="Last Name">
                                <label for="email" class="mt-2">E-mail *</label>
                                <input type="email" name="email"  class="form-control" id="email" placeholder="email">
                                <label for="phone" class="mt-2">Phone *</label>
                                <input type="tel" name="phone"  class="form-control " id="phone" placeholder="+38(0XX)XXX-XX-XX">
                                <fieldset class="form-group mt-2">
                                    <div class="form-check">
                                        <label class="form-check-label">
                                            <input type="radio" class="form-check-input"
                                                   name="gender"
                                                   id="female" value="Female" checked>Female</label>
                                    </div>
                                    <div class="form-check">
                                        <label class="form-check-label">
                                            <input type="radio" class="form-check-input"
                                                   name="gender"
                                                   id="male" value="Male">Male</label>
                                    </div>
                                </fieldset>
                                <label for="date mt-2">Bith Date *</label>
                                <input class="form-control" name="date" type="date" value="1980-08-19" id="date" required>
                                <label for="nationality" class="mt-2">Nationality</label>
                                <select class="custom-select" name="nationality">
                                    <option>Ukranian</option>
                                    <option>Italian</option>
                                    <option>Polish</option>
                                    <option>American</option>
                                    <option>British</option>
                                </select>
                                <div class="mb-4 mt-2">
                                    <label><small> * - required fields </small></label>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="col-lg-4 mt-3">
                        <div class="container">
                            <h4>Last work position</h4>
                            <label for="company_name" class="mt-2">Company</label>
                            <input type="text" name="company" class="form-control" id="company_name" placeholder="Company">
                            <label for="position" class="mt-2">Position</label>
                            <input type="text" name="position" class="form-control" id="position" placeholder="Position">
                            <label for="date_from" class="mt-2">From</label>
                            <input class="form-control" name="date_from" type="date" value="2015-08-01" id="date_from">
                            <label for="date_to" class="mt-2">To</label>
                            <input class="form-control" name="date_to" type="date" value="2018-01-01" id="date_to">
                            <label for="responsibilities" class="mt-2">Tasks and Responsibilities</label>
                            <textarea class="form-control mb-3" rows="7" name="responsibilities"></textarea>
                        </div>
                    </div>
                    <div class="col-lg-4 mt-3">
                        <div class="container" id="parent_prog_lang">
                            <h4>Computer Skills</h4>
                            <label class="mt-2">Programming Languages</label>
                            <div class="row">
                                <div class="col-md-6">
                                    <input class="form-control" name="prog_lang[]" type="text"
                                           list="prog_lang_hint" required>
                                </div>
                                <div class="col-md-6">
                                    <select class="custom-select" name="prog_level[]">
                                        <option>Beginner</option>
                                        <option>Intermediate</option>
                                        <option>Expert</option>
                                    </select>
                                </div>
                            </div>
                        </div>
                        <br/>
                        <div class="container">
                            <div class="row">
                                <div class="col-md">
                                    <button id="remove_prog_lang" class="btn btn-light mr-2 mt-3">Remove
                                        Language
                                    </button>
                                </div>
                                <div class="col-md">
                                    <button id="add_prog_lang" class="btn btn-light mr-2 mt-3">Add Language
                                    </button>
                                </div>
                                <div class="col-md">
                                    <datalist id="prog_lang_hint" class="mr-2">
                                        <option>C</option>
                                        <option>C++</option>
                                        <option>C#</option>
                                        <option>JavaScript</option>
                                        <option>Java</option>
                                    </datalist>
                                </div>
                            </div>
                        </div>
                        <br>
                        <div class="container mt-4" id="parent_lang">
                            <h4>Other Skills</h4>
                            <div id="lang_skills">
                                <div class="row">
                                    <div class="col-md-6">
                                        <label><small>Languages</small></label>
                                        <input class="form-control" name="lang[]" type="text"
                                               list="lang_hint" required>
                                    </div>
                                    <div class="col-md-6">
                                        <label><small>Comprehension</small></label>
                                        <select class="custom-select" name="lang_level_comprehension[]" required>
                                            <option>Beginner</option>
                                            <option>Intermediate</option>
                                            <option>Expert</option>
                                        </select>
                                    </div>
                                </div>
                                <br>
                                <div class="row">
                                    <div class="col-md-6">
                                        <label><small>Reading</small></label>
                                        <select class="custom-select" name="lang_level_reading[]" required>
                                            <option>Beginner</option>
                                            <option>Intermediate</option>
                                            <option>Expert</option>
                                        </select>
                                    </div>
                                    <div class="col-md-6">
                                        <label><small>Writing</small></label>
                                        <select class="custom-select" name="lang_level_writing[]" required>
                                            <option>Beginner</option>
                                            <option>Intermediate</option>
                                            <option>Expert</option>
                                        </select>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <br>
                        <div class="container">
                            <div class="row">
                                <div class="col-md">
                                    <button id="remove_lang" class="btn btn-light mr-2 mt-3">Remove
                                        Language
                                    </button>
                                </div>
                                <div class="col-md">
                                    <button id="add_lang" class="btn btn-light mr-2 mt-3">Add Language
                                    </button>
                                </div>
                                <div class="col-md">
                                    <datalist id="lang_hint" class="mr-2">
                                        <option>English</option>
                                        <option>Italian</option>
                                        <option>Rassian</option>
                                        <option>Ukrainian</option>
                                    </datalist>
                                </div>
                            </div>
                        </div>
                        <div class="container mt-4">
                            <label class="mt-2">Drive's License</label>
                            <div class="form-check m-2">
                                <label class="form-check-label mr-4">
                                    <input class="form-check-input" name="license[]" type="checkbox" value="A">A
                                </label>
                                <label class="form-check-label mr-4">
                                    <input class="form-check-input" name="license[]" type="checkbox" value="B">B
                                </label>
                                <label class="form-check-label mr-4">
                                    <input class="form-check-input" name="license[]" type="checkbox" value="C">C
                                </label>
                            </div>
                            <div class="form-check disabled">
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <br>
            <div class="container col-lg-12 text-center">
                <button type="submit" class="btn btn-light mt-2 mr-2 pl-4 pr-4">Create CV</button>
            </div>
        </fieldset>
    </form>
    <br>
    <footer class="mt-4">
        <div class="text-center" style="opacity: 0.25">
            <label>
                php js jquery bootstrap fonts.google cookie
                <br>
                <small>Kulikova 2018 itstep</small>
            </label>
        </div>
    </footer>
</div>