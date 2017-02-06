<form action="password.php" method="post">
    <fieldset>
        <div class="form-group">
            <input class="form-control" name="oldpassword" placeholder="Current password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="newpassword" placeholder="New password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="confirmpassword" placeholder="Confirm password" type="password"/>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                Reset
            </button>
        </div>
    </fieldset>
</form>
